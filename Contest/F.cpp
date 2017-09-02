#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define mp make_pair
#define mt make_tuple
#define x first
#define y second
#define ii pair<int,int>
#define iii pair<int, ii> 
#define vi vector<int> 
#define maxn 111
#define MOD 1000000007
#define PI 3.14159265358979323846264338327950288

typedef unsigned long long llu;
typedef long long int ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 5*1e14;
const double EPS = 1e-6;
const int mod = 1000000007;

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; scanf("%d",&n);
		int pd[n+1][11111]; 
		int v[n]; REP(i,n) scanf("%d",&v[i]);
		memset(pd,INF,sizeof pd);
		pd[0][0] = 0;
		REP(i,n){
			REP(j,11111){
				if(pd[i][j] != INF){
					pd[i+1][j+v[i]] = min(pd[i+1][j+v[i]],max(pd[i][j], j+v[i]));
					if(v[i] >= j && v[i]-j >= 0) pd[i+1][v[i]-j] = min(pd[i+1][v[i]-j], max(pd[i][j],v[i]-j));
					else if(j-v[i] >= 0) pd[i+1][j-v[i]] = min(pd[i+1][j-v[i]], max(pd[i][j], j-v[i]));
				}
			}
		}
		int res = INF;
		REP(i,11111) res = min(res, pd[n][i]);
		cout << res << endl;
	}
	return 0;
}





