#include <bits/stdc++.h>
#define maxn 11111
#define ii pair<int,int>

using namespace std;

const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;

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
	for(int i = 0; i < n; i++){
		if(deg[i] == 0){
			ts.push(i);
			aux.push(i);
		}
	}
	while(!aux.empty()){
		int u = aux.front(); aux.pop();
		for(int i = 0; i < adj[u].size(); i++){
			deg[adj[u][i]]--;
			if(deg[adj[u][i]] == 0){
				ts.push(adj[u][i]);
				aux.push(adj[u][i]);
			}
		}
	}
	return 0;
}
