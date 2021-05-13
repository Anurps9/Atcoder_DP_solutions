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

	int N, K; cin>>N>>K;

	vi a(N); read(a);

	if(K==0){
		cout<<1;
		return;
	}

	//ways[k][n] = number of ways to distribute k candies among n children
	//ways[k][n] = ways[k][n-1] + ways[k-1][n-1] + ways[k-2][n-1] + ways[k-3][n-1] + ... + ways[k-a[i]][n-1]
	
	vvl ways(K+1, vl(N, 0));
	rep(k,0,K+1){
		rep(n,0,N){
			if(k==0){
				ways[k][n]=1;
			}else if(n==0){
				if(k<=a[0]) ways[k][0]=1+ways[k-1][0];
				else ways[k][0]=ways[k-1][0];
			}else{
				ways[k][n]=ways[k-1][n];
				int tm=min(k, a[n]);
				if(k-tm-1<0){
					ways[k][n] += ways[k][n-1];
				}else{
					ways[k][n] += (ways[k][n-1] - ways[k-tm-1][n-1]);
				}
			}
			ways[k][n]%=mod;
			ways[k][n]+=mod;
			ways[k][n]%=mod;
		}
	}

	cout<<(ways[K][N-1]-ways[K-1][N-1]+mod)%mod<<nl;

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
