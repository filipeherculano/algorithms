/**
 * @file Topological_Sort_Kahn.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#include <bits/stdc++.h>
#define maxn 11111
#define ii pair<int,int>

using namespace std;

int n,m,deg[maxn];
vector<int> adj[maxn];
queue<int> ts;

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a,b;
		scanf("%d %d",&a, &b);
		adj[a].push_back(b);
		deg[b]++;
	}
	queue<int> aux;
	for(int i = 0; i < n; i++)
		if(deg[i] == 0) aux.push(i);

	while(!aux.empty()){
		int u = aux.front(); aux.pop();
		ts.push_back(u);
		for(auto & v : adj[u]){
			deg[v]--;
			if(deg[v] == 0) aux.push(v);
		}
	}
	return 0;
}
