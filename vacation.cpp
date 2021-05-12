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

	//let happ[i][j] = max happiness gainable by doing ith activity on jth day

	int n; cin>>n;

	vvi a(3, vi(n));
	repz(i,n) cin>>a[0][i]>>a[1][i]>>a[2][i];

	vvi happ(3, vi(n,0));
	repz(i,3) happ[i][0]=a[i][0];

	rep(d,1,n){
		repz(i,3){
			repz(j,3){
				if(i==j) continue;
				happ[i][d]=max(happ[i][d],a[i][d]+happ[j][d-1]);
			}
		}
	}

	cout<<max({happ[0][n-1], happ[1][n-1], happ[2][n-1]})<<nl;



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
