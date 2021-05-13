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

	//a1, a2, a3
	//dp_taro[i][j] = the max value (X-Y) taro can obtain from deque[i...j]
	//dp_jiro[i][j] = the min value (X-Y) jiro ...

	int n; cin>>n;
	vl a(n); read(a);

	ll dp_taro[n][n], dp_jiro[n][n];
	repd(i,n-1,0){
		rep(j,0,n){
			if(i>j) continue;
			if(i==j){
				dp_taro[i][j]=a[i]; dp_jiro[i][j]=-a[i];
			}else{	
				dp_taro[i][j] = max(a[i]+dp_jiro[i+1][j], a[j]+dp_jiro[i][j-1]);
				dp_jiro[i][j] = min(dp_taro[i+1][j]-a[i], dp_taro[i][j-1]-a[j]);
			}
		}
	} 

	cout<<dp_taro[0][n-1]<<nl;

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
