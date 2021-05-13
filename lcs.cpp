#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define INF (int)2e9
#define mod 1000000007
#define PI 3.141592653589793238
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define repd(i,a,b) for(int i=a; i>=b; --i)
#define repz(i,b) for(int i=0; i<b; ++i)
#define repdz(i,b) for(int i=b; i>=0; --i)
#define trav(i,a) for(int i: a)
#define pb push_back
#define pf push_front
#define nl '\n'
#define sp ' '
#define sz(a) a.size()
#define read(p) repz(i,sz(p)) cin>>p[i]

typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>>  vvl;
typedef pair<int, int> pii;

void solve(){

	string s, t; cin>>s>>t;

	vvi lcs(sz(s)+1, vi(sz(t)+1, 0));

	rep(i,1,sz(s)+1) {
		rep(j,1,sz(t)+1){
			if(s[i-1]==t[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
			else lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
		}
	}

	string ans="";
	int i=sz(s), j=sz(t);
	while(i>=1 && j>=1){
		if(s[i-1]==t[j-1]) {
			ans=s[i-1]+ans;
			i--; j--;
		}else if(lcs[i-1][j]>lcs[i][j-1]){
			i--;
		}else{
			j--;
		}
	}

	cout<<ans<<nl;


}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	int ts=1;
	//cin>>ts;
	while(ts--){
		solve();
	}
	return 0;
	
}
