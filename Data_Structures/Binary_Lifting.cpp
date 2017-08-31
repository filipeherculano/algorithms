#include <bits/stdc++.h>
#define maxn 111111
#define LSOne(S) (S & (-S))

using namespace std;

const double EPS = 1e-6;

int n, q, Depth[maxn], Table[20][maxn], maxEdge[20][maxn], minEdge[20][maxn], D;
vector<int> adj[maxn], wadj[maxn];

// dfs rooted at node 0
void dfs(int i, int p, int d, int dist){
	Depth[i] = d;
	Table[0][i] = p;
	if(i) maxEdge[0][i] = minEdge[0][i] = dist;
	if(d) D = max(D, (int)log2( d ));
	for(int j = 0; j < (int) adj[i].size(); j++){
		if(adj[i][j] != p){
			dfs(adj[i][j], i, d+1, wadj[i][j]);
		}
	}
}

void build(){
	for(int i = 1; i <= D; i++){
		for(int j = 0; j < n; j++){
			int mid = Table[i-1][j];
			if(mid != -1){
				Table[i][j] = Table[i-1][mid];
				minEdge[i][j] = min(minEdge[i-1][j], minEdge[i-1][mid]);
				maxEdge[i][j] = max(maxEdge[i-1][j], maxEdge[i-1][mid]);
			}
		}
	}
}

int walk(int i, int k){
	for(;k && i != -1; k -= LSOne(k)) i = Table[(int) log2( LSOne(k) )][i];
	return i;
}

int lca(int u, int v){
	if(Depth[u] < Depth[v]) v = walk(v,Depth[v]-Depth[u]);
	if(Depth[v] < Depth[u]) u = walk(u,Depth[u]-Depth[v]);
	if(u == v) return u;
	
	for(int d = D; d >= 0; d--){
		if(Table[d][u] != Table[d][v]){
			u = Table[d][u];
			v = Table[d][v];
		}
	}
	return Table[0][u];
}

int min_query(int u, int v){
	int res = 0x3f3f3f3f;
	int LCA = lca(u,v);
	int k = Depth[u] - Depth[LCA];
	for(;k && u != -1; k -= LSOne(k)) {
		res = min(res, minEdge[(int) log2( LSOne(k) )][u]);
		u = walk(u, LSOne(k));	
	}
	k = Depth[v] - Depth[LCA];
	for(;k && v != -1; k -= LSOne(k)) {
		res = min(res, minEdge[(int) log2( LSOne(k) )][v]);
		v = walk(v, LSOne(k));	
	}
	return res;
}

int max_query(int u, int v){
	int res = 0;
	int LCA = lca(u,v);
	int k = Depth[u] - Depth[LCA];
	for(;k && u != -1; k -= LSOne(k)) {
		res = max(res, maxEdge[(int) log2( LSOne(k) )][u]);
		u = walk(u, LSOne(k));	
	}
	k = Depth[v] - Depth[LCA];
	for(;k && v != -1; k -= LSOne(k)) {
		res = max(res, maxEdge[(int) log2( LSOne(k) )][v]);
		v = walk(v, LSOne(k));	
	}
	return res;
}

int main(){
	memset(Table, -1, sizeof Table);
	memset(minEdge, 0x3f3f3f3f, sizeof minEdge);

	scanf("%d %d",&n,&q);
	for(int i = 1; i < n ; i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w); a--; b--;
		adj[a].push_back(b); wadj[a].push_back(w);
		adj[b].push_back(a); wadj[b].push_back(w);
	}
	dfs(0,-1,0,0);
	build();
	for(int i = 0; i < q; i++){
		int a,b;
		scanf("%d %d",&a,&b); a--; b--;
		cout << "MIN: " << min_query(a,b) << endl;
		cout << "MAX: " << max_query(a,b) << endl;
	}
	return 0;
}
