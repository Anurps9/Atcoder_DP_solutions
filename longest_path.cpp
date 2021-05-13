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

vvi par, child;

void dfs(int v, vi &topo, vi &vis){	
	vis[v]=1;
	trav(a, child[v]) if(!vis[a]) dfs(a,topo,vis);
	topo.pb(v);
}

void solve(){

	int n, m; cin>>n>>m;
	par=vvi(n); child=vvi(n);

	repz(i,m){
		int a, b; cin>>a>>b; a--, b--;
		par[b].push_back(a); child[a].push_back(b);
	}

	vi topo; vi vis(n,0);	

	repz(i,n) if(!vis[i]) dfs(i, topo, vis);

	reverse(all(topo));

	//longestPath[i] is the length of the longest path ending at vertex i
	vi longestPath(n);
	int ans=0;
	trav(i,topo){
		longestPath[i]=0;
		trav(p,par[i]) longestPath[i]=max(longestPath[i], 1+longestPath[p]);
		ans=max(ans, longestPath[i]);
	}

	// trav(a,longestPath) cout<<a<<sp; cout<<nl;
	cout<<ans<<sp;


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
