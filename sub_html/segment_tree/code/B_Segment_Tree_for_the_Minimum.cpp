#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(), v.end()
#define in_array(a) for(auto &c:a)cin>>c
using namespace std;
vector<ll>tree, a;
void build_tree(int id, int l, int r){
	if(l==r){
		tree[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build_tree(id*2, l, mid);
	build_tree(id*2+1, mid+1, r);
	tree[id]=min(tree[id*2], tree[id*2+1]);
}
void update(int id, int l, int r, int i, int v){
	if(i<l || i>r)
		return ;
	if(l==r && r==i){
		tree[id]=v;
		return;
	}
	int mid= (l+r)/2;
	update(id*2, l, mid, i, v);
	update(id*2+1, mid+1, r, i, v);
	tree[id]= min(tree[id*2], tree[id*2+1]);
}
int get_val(int id, int l, int r, int u, int v){
	if(v<l || u>r)
		return INT_MAX;
	if(u <= l && r <= v)
		return tree[id];
	int mid= (l+r)/2;
	return min( get_val(id*2, l, mid, u,v), get_val(id*2+1, mid+1, r, u,v));
}
int main(){
 ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 int n,m;
 cin>>n>>m;
 a.resize(n+1);
 tree.resize(n*4);
 for(int i=1;i<=n;i++)
 	cin>>a[i];
 	build_tree(1, 1, n);
// 	for(auto c:tree)
// 		cout<<c<<" ";cout<<'\n';
 	while(m--){
 		int c,d,e;
 		cin>>c>>d>>e;
 		if(c==1){
 			update(1, 1,n,d+1,e);
		 }
		else{
			cout<<get_val(1,1,n,d+1,e)<<"\n";
		}
	 }
}
