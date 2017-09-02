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
		string s;
		int n; cin>>s>>n;
		deque<char> p; int cont;
		
		
		cont = 0; p.clear();
		for(auto c: s){
			if(p.empty()) p.push_back(c);
			else{
				while(cont<n && !p.empty() && p.back()>c){
					p.pop_back(); cont++;
				}
				p.push_back(c);
			}
		}
		while(cont<n){
			p.pop_back(); cont++;
		}
		for(auto c: p){
			printf("%c", c);
		} printf("\n");
		
		cont = 0; p.clear();
		for(auto c: s){
			if(p.empty()) p.push_back(c);
			else{
				while(cont<n && !p.empty() && p.back()<c){
					p.pop_back(); cont++;
				}
				p.push_back(c);
			}
		}
		while(cont<n){
			p.pop_back(); cont++;
		}
		for(auto c: p){
			printf("%c", c);
		} printf("\n");
	}
	
	return 0;
}
