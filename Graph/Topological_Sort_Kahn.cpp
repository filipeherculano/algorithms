/**
 * @file Topological_Sort_Kahn.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 11111

using namespace std;

int n,deg[maxn];
vector<int> adj[maxn];
queue<int> ts;

int Topological(){
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
}
