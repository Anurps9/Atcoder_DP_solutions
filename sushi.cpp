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
	vi p(n); read(p);

	vi cnt(4);
	trav(i, p) cnt[i]++;

	//opr[a][b][c] is the expected number of operations when a dish with sushi, b dishes with 2 sushis,
	//c dishes with 3 sushis are left
	double opr[n+5][n+5][n+5];
	opr[0][0][0]=0;

	rep(c,0,n+1){
		rep(b,0,n+1){
			rep(a,0,n+1){
				//E(X)= p0x0 + p1x1 + p2x2 + p3x3
				//(1-p0)*opr[a][b][c] = p3*(1+opr[a][b+1][c-1]) + p2*(1+opr[a+1][b-1][c]) + p1*(1+opr[a-1][b][c]) + p0
				if(a+b+c>n || a+b+c==0) continue;
				opr[a][b][c]=0;
				if(c>=1) opr[a][b][c]+=(double)c/n * (1+opr[a][b+1][c-1]);
				if(b>=1) opr[a][b][c]+=(double)b/n * (1+opr[a+1][b-1][c]);
				if(a>=1) opr[a][b][c]+=(double)a/n * (1+opr[a-1][b][c]);
				double p0=(double)(n-a-b-c)/n;
				opr[a][b][c]+=p0;
				opr[a][b][c]/=(1-p0);

			}
		}
	}

	cout<<opr[cnt[1]][cnt[2]][cnt[3]]<<nl;
	

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
