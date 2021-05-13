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

	//the person who will play last will win
	//any person will win if at the time of his turn, there can only be an odd number of moves
	//dp_x[k][i] if x will definitely win by choosing ith element from A if remaining number of stones is k
	//dp_taro[k][i] =  !dp_jiro[k-a[i]][0] && !dp_jiro[k-a[i]][1] && !dp_jiro[k-a[i]][2] ...
	//dp_jiro[k][i] =  !dp_taro[k-a[i]][0] && !dp_taro[k-a[i]][1] && !dp_taro[k-a[i]][2] ...

	int n, K; cin>>n>>K;
	vi a(n); read(a);

	bool dp_taro[K+1][n], dp_jiro[K+1][n];
	rep(k,0,K+1){
		rep(i,0,n){
			if(k-a[i]<0){
				dp_taro[k][i]=false;
			}else if(k-a[i]==0){
				dp_taro[k][i]=true;
			}else{
				dp_taro[k][i] = true;
				rep(j,0,n){
					dp_taro[k][i] &= !dp_jiro[k-a[i]][j];
				}
			}
			if(k-a[i]<0){
				dp_jiro[k][i]=false;
			}else if(k-a[i]==0){
				dp_jiro[k][i]=true;
			}else{
				dp_jiro[k][i]=true;
				rep(j,0,n){
					dp_jiro[k][i] &= !dp_taro[k-a[i]][j];
				}
			}
		}
	}

	//check for taro if for any dp[K][i] he will definitely win
	//if so then he wins, otherwise no matter what is his first move there is some move jiro can play after that to definitely win
	rep(i,0,n){
		if(dp_taro[K][i]){
			cout<<"First"<<nl;
			return;
		}
	}

	cout<<"Second"<<nl;

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
