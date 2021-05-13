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

	int n; cin>>n;
	vl a(n,0); read(a);

	vvl minCost(n,vl(n,(ll)INF*INF));

	vl pre(n+1,0);
	rep(i,1,n+1) pre[i]=pre[i-1]+a[i-1];

	repd(i,n-1,0){
		rep(j,i,n){
			if(j==i) minCost[i][j]=0;
			rep(k,i,j){
				minCost[i][j]=min(minCost[i][j], minCost[i][k]+minCost[k+1][j]+pre[j+1]-pre[i]);
			}
		}
	}

	cout<<minCost[0][n-1]<<nl;

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
