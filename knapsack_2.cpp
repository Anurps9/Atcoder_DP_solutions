#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define INF (ll)2e15
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

	//weight[i][v] = minimum weight to gain v value with first i items
	ll n, W; cin>>n>>W;
	ll N=(ll)1e5+5;
	vl w(n+1), v(n+1); repz(i,n) cin>>w[i]>>v[i];

	vvl weight(n+1, vl(N+1, INF));

	rep(i,0,n+1){
		rep(val,0,N+1){
			if(val==0) weight[i][val]=0;
			else if(i==0) weight[i][val]=INF;
			else{
				if(val>=v[i-1]) weight[i][val]=min(weight[i-1][val-v[i-1]]+w[i-1], weight[i-1][val]);
				else weight[i][val]=weight[i-1][val];
			}
		}
	}

	ll ans=0;
	repz(i,N+1) if(weight[n][i]<=W) ans=i; 

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
