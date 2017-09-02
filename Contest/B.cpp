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
#define maxn 1111

typedef unsigned long long llu;
typedef long long int ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const int mod = 1000000007;

using namespace std;

ll n,t,mat[3][3], v[3], r[3][3];

void mult(bool isOdd){
	ll aux[3][3]; memset(aux,0,sizeof aux);
	if(isOdd){
		REP(i,3) REP(j,3) REP(k,3) aux[i][j] = (aux[i][j] + (mat[i][k] * r[k][j]) % mod) % mod;
		REP(i,3) REP(j,3) r[i][j] = aux[i][j];
	} else {
		REP(i,3) REP(j,3) REP(k,3) aux[i][j] = (aux[i][j] + (mat[i][k] * mat[k][j]) % mod) % mod;
		REP(i,3) REP(j,3) mat[i][j] = aux[i][j];
	}
}

int main(){
	cin >> t;
	while(t--){
		scanf("%lld",&n);
		memset(r,0,sizeof r); REP(i,3) r[i][i] = 1;
		v[0] = v[1] = v[2] = 1;
		mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
		mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
		mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;
		n--;
		while(n){
			if(n&1) mult(true);
			mult(false);
			n /= 2;
		}
		ll res = 0;
		REP(i,3) REP(j,3) res = (res + (v[j] * r[j][i]) % mod) % mod;
		cout << res << endl;
	}
	return 0;
}
