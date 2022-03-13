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
const ll m=1e9+7;
int main(){
 ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 freopen("input.inp", "r", stdin);
 int t;
 cin>>t;
 while(t--){
 	int h; 2
 	vector<int> d(h); //do dai
 	for (auto &c: d)
 		cin>>c;
 	ll ans,n; cin>>n;
 	vector<string> dic(n);
 	vector<string> ques;
 	map<int, vector<string> > key,key2;
 	for(auto &c: dic){
 		cin>>c;
		if(c.length()== h)
			ques.pb(c);
		key[c.length()].pb(c);
	 }
	 key2=key;
	for(int i=0;i<ques.size();i++){
		int k=0,res1=1;
	 	for(int j=0;j<ques[i].length();j++){   // ques[i] is vector contain hidden word
	 		int res=0;
	 		res1= 1;
	 		for(int o=0;o< key[d[j]].size();o++){     // d[j] is length and key[d[j]] include elements have length equal d[j]
	 			if(ques[i][j] == key[d[j]][o][0]){
	 				res++;
	 				key[d[j]].erase(key[d[j]].begin()+o);
				 }
			 }
			if(res!=0)
				k++;
			res1= ((res1%m) * (res%m))%m;
			key==key2;
		 }
		 if(k == ques[i].size())
		 	ans = ((ans%m) + (res1%m))%m;	
	}
	 cout<<ans<<'\n';
     cout<<"sad"
 }
}
