/**
 * @file Dijkstra.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#include <bits/stdc++.h>
#define maxn 11111
#define ii pair<int,int>

using namespace std;

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
			int v = adj[u][i], w = wadj[u][i];
			if(dist[v] > d + w){
				dist[v] = d + w;
				pq.push({dist[v], v});
			}
		}
	}
	return -1;
}