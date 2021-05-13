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
	vector<double> p(n); repz(i,n) cin>>p[i];

	//prob[h][t] = probability of having h heads in the toss of first t coins
	vector<vector<double>> prob(n+1,vector<double>(n+1,0));
	prob[0][0]=1;

	rep(t,1,n+1){
		repz(h,n+1){
			if(h==0) prob[0][t]=(1.0-p[t-1])*prob[0][t-1];
			else prob[h][t]=p[t-1]*prob[h-1][t-1] + (1.0-p[t-1])*prob[h][t-1];
		}
	}

	double ans=0;
	rep(h,1,n+1){
		if(h>n-h){
			ans+=prob[h][n];
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
