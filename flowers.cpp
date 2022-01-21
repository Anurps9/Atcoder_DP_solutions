#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF (int)2e9
#define mod 1000000007
#define PI 3.141592653589793238
#define FASTIO() ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cout<<"[ "<<#x<<sp<<": "<<x<<" ]"<<nl; 
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

int H=(int)2e5+5;

vi tree;

void update(int pos, int val){
	pos+=H;
	tree[pos]=max(val, tree[pos]);
	while(pos/2>=1){
		pos/=2;
		tree[pos]=max(tree[2*pos], tree[2*pos+1]);
	}
}

int find(int node, int ql, int qr, int tl, int tr){
	if(ql>tr || qr<tl) return 0;
	if(tr<=qr && tl>=ql) return tree[node];

	int mid=(tl+tr)/2;
	return max(find(2*node, ql, qr, tl, mid),
				find(2*node+1, ql, qr, mid+1, tr));
}

void solve(){

	//dp_without[n] = max beauty among n flowers not considering nth flower
	//dp_with[n] = max beauty among n flowers considering nth flower

	//dp_without[n]=max(dp_without[n-1], dp_with[n-1])
	//dp_with[n]=b[n]+max(dp_with[m]), h(m)<h(n) & m<n

	while(__builtin_popcount(H)!=1) H++;
	tree.assign(2*H,0);


	int n; cin>>n;
	vi h(n), b(n); read(h); read(b);
	vi dp_without(n+1), dp_with(n+1);

	dp_without[0]=0; dp_with[0]=0;

	rep(i,1,n+1){
		dp_without[i]=max(dp_without[i-1], dp_with[i-1]);
		int tmp=find(1,0,h[i-1]-1,0,H-1);
		dp_with[i]=b[i-1]+tmp;
		update(h[i-1], dp_with[i]);
	}

	cout<<max(dp_with[n], dp_without[n])<<nl;


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

