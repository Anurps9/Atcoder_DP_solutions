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

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

void solve(){

	int n; cin>>n;
	vi h(n); read(h);

	if(n==1){
		cout<<0<<nl; return;
	}

	vi cost(n);
	cost[0]=0; cost[1]=abs(h[1]-h[0]);

	rep(i,2,n) cost[i]=min(cost[i-1]+abs(h[i]-h[i-1]), cost[i-2]+abs(h[i]-h[i-2]));

	cout<<cost[n-1]<<nl;


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
