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

int t,n,m;
vi adj[maxn];
vector<ii> wadj[maxn];

void dijkstra(int s, int e){
	vector<ii> dist(n,{INF,INF}); dist[s] = {0,0};
	priority_queue<iii, vector<iii>, greater<iii> > pq; pq.push({{0,0},s});
	while(!pq.empty()){
		int u = pq.top().y;
		ii d = pq.top().x;
		pq.pop();
		if(d > dist[u]) continue;
		if(u == e){
			printf("%d %d\n", d.x, d.y);
			return;
		}
		
		REP(j,adj[u].size()){
			ii temp = d;
			if(wadj[u][j].y == 1) temp.x += wadj[u][j].x;
			temp.y += wadj[u][j].x;
			
			if(dist[adj[u][j]] > temp){
				dist[adj[u][j]] = temp;
				pq.push({dist[adj[u][j]], adj[u][j]});
			}
		}
	}
	puts("-1");
}

int main(){
	cin >> t;
	while(t--){
		scanf("%d %d",&n,&m);
		REP(i,m){
			int a,b,c,d;
			scanf("%d %d %d %d",&a,&b,&c,&d); a--; b--;
			adj[a].pb(b); wadj[a].pb({c,d});
			adj[b].pb(a); wadj[b].pb({c,d});
		}
		int s,e; scanf("%d %d",&s,&e); s--; e--;
		dijkstra(s,e);
		
		REP(i,n) {
			adj[i].clear();
			wadj[i].clear();
		}
	}
	return 0;
}
