#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define nl '\n'
#define sp ' '
#define rep(i, a, b) for(int i=a; i<b; ++i)
#define repd(i, a, b) for(int i=a; i>=b; --i)
#define repz(i, b) for(int i=0; i<b; ++i)
#define trav(i, a) for(int i: a)
#define read(a) repz(i, a.size()) cin>>a[i];
#define sz(a) a.size()
#define PI 3.141592653589793238
#define mod 1000000007
#define INF (int)1e18

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<bool> vb;


namespace mod_operations{
	int modAdd(int n, int m){
		n=(n%mod+mod)%mod; m=(m%mod+mod)%mod;
		return (n+m)%mod;
	}
}
using namespace mod_operations;


void solve(){

	int n;
	cin>>n;

	vvi a(n, vi(n));
	repz(i, n) repz(j, n) cin>>a[i][j];

	vvi dp(n+1, vi(1<<n));
	dp[0][0] = 1;

	rep(i, 1, n+1){
		rep(msk, 0, (1<<n)){
			if(__builtin_popcount(msk) != i) continue;
			repz(b, n){
				if(msk & (1<<b) && a[i-1][b]){
					dp[i][msk] = modAdd(dp[i][msk], dp[i-1][msk & ~(1<<b)]);
				}
			}
		}
	}

	cout<<dp[n][(1<<n)-1];

}

signed main(){


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);

	// freopen("output.txt", "w", stdout);
	// freopen("input.txt", "r", stdin);

	int ts=1;
	//cin>>ts;
	while(ts--) {
		solve();
	} 
	return 0;

}
