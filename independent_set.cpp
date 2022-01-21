#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF (int)2e9
#define mod 1000000007
#define PI 3.141592653589793238
#define FASTIO() ios::sync_with_stdio(0); cin.tie(0);
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define srt(a) sort(all(a))
#define rev(a) reverse(all(a))
#define sz(a) a.size()
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define repd(i,a,b) for(int i=a; i>=b; --i)
#define trav(i,a) for(auto &i: a)
#define read(p) rep(i,0,sz(p)) cin>>p[i]
#define pb push_back
#define pf push_front
#define nl '\n'
#define sp ' '

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<bool> vb;
typedef vector<vb> vvb;	

vi black, white;
vvi adj;

void dfs(int v, int prev){
	trav(a,adj[v]){
		if(a!=prev){
			dfs(a,v);
			white[v]*=(black[a]+white[a]);
			black[v]*=(white[a]);
			white[v]%=mod;
			black[v]%=mod;
		}
	}
}

void solve(){

	int n; cin>>n;

	if(n==1){
		cout<<2<<nl;
		return;
	}

	black.assign(n,1);
	white.assign(n,1);
	adj=vvi(n, vi()); 

	rep(i,0,n-1) {
		int u, v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}

	dfs(0,0);

	cout<<(black[0]+white[0])%mod<<nl;

}

signed main(){

	FASTIO();
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	int ts=1;
	// cin>>ts;
	rep(i,0,ts) solve();
	return 0;

}

