#include <bits/stdc++.h>
#define maxn 11111
#define ii pair<int,int>

using namespace std;

const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;

int n,m;
vector<int> adj[maxn], wadj[maxn];

int dijkstra(int s, int e){
	vector<int> dist(n, INF); dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0,s});
	while(!pq.empty()){
		int u = pq.top().second, d = pq.top().first; pq.pop();
		if(d > dist[u]) continue;
		if(u == e) return d;
		for(int i = 0; i < adj[u].size(); i++){
			if(dist[adj[u][i]] > d + wadj[u][i]){
				dist[adj[u][i]] = d + wadj[u][i];
				pq.push({dist[adj[u][i]], adj[u][i]});
			}
		}
	}
	return -1;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a,b,w;
		scanf("%d %d %d",&a, &b, &w);
		adj[a].push_back(b); wadj[a].push_back(w);
		adj[b].push_back(a); wadj[b].push_back(w);
	}
	return 0;
}
