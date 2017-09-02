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
#define maxn 111
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

ll n,m,t,mat[2][2], v[2], r[2][2];

void mult(bool isOdd){
	ll aux[2][2]; memset(aux,0,sizeof aux);
	if(isOdd){
		REP(i,2) REP(j,2) REP(k,2) aux[i][j] = (aux[i][j] + (mat[i][k] * r[k][j]) % mod) % mod;
		REP(i,2) REP(j,2) r[i][j] = aux[i][j];
	} else {
		REP(i,2) REP(j,2) REP(k,2) aux[i][j] = (aux[i][j] + (mat[i][k] * mat[k][j]) % mod) % mod;
		REP(i,2) REP(j,2) mat[i][j] = aux[i][j];
	}
}

int main(){
	cin >> t;
	while(t--){
		scanf("%lld %lld",&m, &n);
		if(n == 0){
			puts("0");
			continue;
		}
		memset(r,0,sizeof r); REP(i,2) r[i][i] = 1;
		v[0] = 0; v[1] = 1;
		int exp = log10(n)+1;
		REP(i,exp) v[1] = (v[1]*10) % mod;
		mat[0][0] = 1; mat[0][1] = 0;
		mat[1][0] = 1; mat[1][1] = v[1]; 
		v[1] = 1;
		while(m){
			if(m&1) mult(true);
			mult(false);
			m /= 2;
		}
		ll res = 0;
		res = (v[0] * r[0][0]) % mod + (v[1] * r[1][0]) % mod;
		res %= mod;
		res = (res * n) % mod;
		cout << res << endl;
	}
	return 0;
}
