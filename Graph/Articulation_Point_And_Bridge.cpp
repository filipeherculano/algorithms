#define maxn 10000

int dfs_low[maxn], dfs_num[maxn], count;
vector<int> adj[maxn];

void ArticulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = count++;
	for(int j = 0; j < (int) adj[u].size(); j++){
		int v = adj[u][j];
		if(dfs_num[] == UNVISITED){
			
		} else if()
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}

	return 0;
}
