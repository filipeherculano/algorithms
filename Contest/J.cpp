#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(), a.end()
#define pb push_back
#define LSOne(S) (S & (-S))
#define dbg(x) cerr << ">> " << x << endl;
#define _ << " , " <<
#define mp make_pair
#define mt make_tuple
#define x first
#define y second
#define ii pair<int,int>
#define point pair<double,double>
#define maxn 111111
#define vi vector<int>
#define iii pair< ii, int > 

typedef unsigned long long llu;
typedef long long int ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const int mod = 1000000007;

using namespace std;

ll t,n,m,ptr[maxn],cap[maxn], v[maxn];

ll father(ll i){
	if(ptr[i] == i) return i;
	return ptr[i] = father(ptr[i]);
}

ll rmv(ll x, ll y){
	ll res = 0;
	if(cap[x] >= y) cap[x] -= y;
	else {
		y -= cap[x];
		cap[x] = 0;
		ll p = father(x);
		if(p == x) {
			if(x == n) return y;
			else {
				ptr[x] = father(x+1);
				res += rmv(ptr[x],y);
			}
		} else res += rmv(p,y);
	}
	return res;
}

int main(){
	cin >> t;
	while(t--){
		ll res = 0;
		memset(ptr, 0, sizeof ptr);
		memset(cap, 0, sizeof cap);
		memset(v, 0, sizeof v);
		scanf("%lld %lld", &n, &m);
		REP(i,n) scanf("%lld",&cap[i]), v[i] = cap[i];
		REP(i,n+1) ptr[i] = i;
		REP(i,m){
			ll x,y; scanf("%lld %lld",&x,&y); x--;
			res += rmv(x,y);
		}
		cout << res << endl;
		REP(i,n) {
			cout << v[i]-cap[i];
			if(i == n-1) puts("");
			else cout << " ";
		}
	}
	return 0;
}
