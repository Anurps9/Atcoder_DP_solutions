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

	int h, w; cin>>h>>w;
	vector<string> grid(h);
	repz(i,h) cin>>grid[i];

	vvl path(h, vl(w,0));
	path[0][0]=1;

	repz(i,h) repz(j,w){
		if(i-1>=0 && grid[i-1][j]=='.') path[i][j]+=path[i-1][j];
		if(j-1>=0 && grid[i][j-1]=='.') path[i][j]+=path[i][j-1];
		path[i][j]%=mod;
	}

	cout<<path[h-1][w-1]<<nl;

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
