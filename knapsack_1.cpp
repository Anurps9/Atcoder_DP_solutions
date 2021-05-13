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
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve(){

	//val[i][c] = max value of items selected from first i items, when capacity of the bag is w
	ll n, W; cin>>n>>W;
	vl w(n), v(n); repz(i,n) cin>>w[i]>>v[i];

	vvl val(n+1, vl(W+1,0));

	rep(i,1,n+1){
		rep(c,1,W+1){
			//select the i-1 th item or not
			if(c<w[i-1]) val[i][c]=val[i-1][c];
			else val[i][c]=max(val[i-1][c], val[i-1][c-w[i-1]]+v[i-1]);
		}
	}

	cout<<val[n][W]<<nl;

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
