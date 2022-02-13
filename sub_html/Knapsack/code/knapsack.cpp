#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(), v.end()
#define in_array(a) for(auto &c:a)cin>>c
using namespace std;
int main(){
 ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 ll n, w;
 cin>>n>>w;
 vector<pair<ll,ll>> a(n+1);
 for( int i=1;i<=n;i++)
 	cin>>a[i].F>>a[i].S;
	vector<vector<ll> > val(n+1, vector<ll> (w+1,0));
	for(int i=1;i<=n;i++){
		ll kg= a[i].F, cost=a[i].S;
		for(int j=1;j<=w;j++){
			if(j-kg>=0){
				val[i][j]=max(val[i-1][j], val[i-1][j-kg] + cost);
			}
			else	val[i][j]= val[i-1][j];
		}
	}
cout<<val[n][w];
}
