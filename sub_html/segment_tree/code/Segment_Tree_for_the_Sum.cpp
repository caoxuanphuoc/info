#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(), v.end()
#define in_array(a) for(auto &c:a)cin>>c
using namespace std;
vector<ll> a;
vector<ll> tree;
void build_tree(int id, int l, int r){
	if(l==r){
		tree[id]= a[r];
		return;
	}
	int mid= (l+r)/2;
	build_tree(id*2, l, mid);
	build_tree(id*2+1, mid+1, r);
	tree[id]= tree[id*2] + tree[id*2+1];
}
void set_val(int id,int l, int r, int i, int val){
	if(i<l || i>r)
		return;
	if(l==r && i==r){
		tree[id]= val;
		return;
	}
	int mid= (l+r)/2;
	set_val(id*2, l, mid, i, val);
	set_val(id*2+1, mid+1, r, i, val);
	tree[id]= tree[id*2]+ tree[id*2+1];
}
ll get_sum(int id, int l, int r, int u, int v){
	if(v<l || u>r)
		return 0;
	if(u<=l && r<=v)
		return tree[id];
	int mid= (l+r)/2;
	return get_sum(id*2,l,mid, u,v) + get_sum(id*2+1, mid+1, r, u, v);
}
int main(){
 ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 ll n,m;
 cin>>n>>m;
 a.resize(n+1);
 tree.resize(4*n);
 for(int i=1; i<= n;i++)
 	cin>>a[i];
build_tree(1,1,n);
 while(m--){
 	int c,d,e;
 	cin>>c>>d>>e;
 	if(c==1){
 		set_val(1,1,n,d+1,e);
	 }
	 else
	 	cout<<get_sum(1,1,n,d+1,e)<<'\n';
 }
}	
