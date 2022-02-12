#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
using namespace std;
 vector<int> a;
 void build_tree(int id, int l, int r, vector<int> &tree){
 	if(l==r){
 		tree[id]=a[l];
 		return;
	 }
 	int mid= (l+r)/2;
 	build_tree(id*2, 1, mid, tree);
 	build_tree(id*2+1, mid+1, r, tree);
 	tree[id]= min(tree[id*2],tree[id*2+1]);
 }
 void update(int id, int l, int r, int i, int v, vector<int> &tree){
 	if(i<l || i>r)
 		return;
 	if(i==l && l==r){
 		tree[id]=v;
 		return;
	 }
 	int mid= (l+r)/2;
 	update(id*2, l, mid, i, v,tree);
 	update(id*2+1, mid+1, r, i, v, tree);
 	tree[id]= min(tree[id*2], tree[id*2+1]);
 }                 
 int get_min(int id, int l, int r, int u, int v,vector<int> &tree){
 	if(v< l || r< u)
 		return INT_MAX;
 	if(r==l)//u<=l && r<=u
 		return tree[id];
 	int mid= (l+r)/2;
 	return min( get_min(id*2, l, mid, u, v, tree),
	 			get_min(id*2+1,mid+1, r, u, v, tree));
 }
 int main(){
 	 ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 int n,q;
 cin>>n>>q;
 vector<int> tree(n*4,0);
 a.resize(n+1);
 	for(int i=1;i<=n;i++)
 		cin>>a[i];
 build_tree(1,1,n,tree);
 while(q--){
 	char x;
 	cin>>x;
 	if(x=='U'){
 		int i,v; 	// i is pos and v is value
 		cin>>i>>v;
 	 	update(1 ,1 ,n ,i ,v ,tree);
	 }
	else{
		int u,v;
		cin>>u>>v; //[u,v] is length sub_array
       cout<<get_min(1, 1, n, u, v ,tree)<<"\n";	
	}
 }
}
