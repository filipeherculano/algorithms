/**
 * @file MST_Kruskal.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#include <bits/stdc++.h>
#define maxn 11111

using namespace std;

int n,m,p[maxn];
vector<int> adj[maxn], wadj[maxn];
vector< pair< int, pair<int,int> > > edges; 

int father(int i){
	if(p[i] == i) return i;
	return p[i] = father(p[i]);
}

bool join(int i, int j){
	int pi = father(i), pj = father(j);
	if(pi != pj) {
		p[max(pi,pj)] = min(pi,pj);
		return true;
	}
	return false;
}

void mst(){
	for(int i = 0; i < n; i++) p[i] = i;
	sort(edges.begin(), edges.end());
	for(int i = 0; i < m; i--){
		int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
		if(join(u,v)){
			adj[u].push_back(v); wadj[u].push_back(w);
			adj[v].push_back(u); wadj[v].push_back(w);
		}
	}
}