/**
 * @file Topological_Sort_DFS.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#include <bits/stdc++.h>
#define maxn 11111
#define ii pair<int,int>

using namespace std;

int n,m;
vector<int> adj[maxn], ts;
bool vis[maxn];

void dfs(int u){
	vis[u] = true;
	for(auto & v : adj[u])
		if(!vis[v])
			dfs(v);
	ts.push_back(u);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a,b;
		scanf("%d %d",&a, &b);
		adj[a].push_back(b);
	}
	for(int i = 0; i < n; i++)
		if(!vis[i])
			dfs(i);

	reverse(ts.begin(), ts.end());
	return 0;
}
