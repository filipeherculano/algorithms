#include <bits/stdc++.h>

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(a); i < (int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
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

int main(){
	int t; cin>>t;
	while(t--){
		string s1,s2; cin>>s1>>s2;
		int contador1[1500], contador2[1500];
		for(int i='a'; i<='z'; i++) {contador1[i]=0; contador2[i]=0;}
		for(auto x: s1) contador1[x]++;
		for(auto x: s2) contador2[x]++;
		int res = 0;
		for(int i='a'; i<='z'; i++) res += abs(contador1[i]-contador2[i]);
		cout<<res<<endl;
	}
	
	return 0;
}
