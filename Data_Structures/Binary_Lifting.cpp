/** 
 * @file Binary_Lifting.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-07-25
 */
#define maxn 100000
#define LSOne(S) (S & (-S))

using namespace std;

int n, Depth[maxn], Table[20][maxn], maxEdge[20][maxn], minEdge[20][maxn], D;
vector<int> adj[maxn], wadj[maxn];

void dfs(int i, int p, int d, int dist){
	Depth[i] = d;
	Table[0][i] = p;
	maxEdge[0][i] = minEdge[0][i] = dist;
	if (d) D = max(D, (int)log2(d));
	for (int j = 0; j < (int)adj[i].size(); j++)
		if (adj[i][j] != p) dfs(adj[i][j], i, d+1, wadj[i][j]);
}

void build(){
	for (int i = 1; i <= D; i++){
		for (int j = 0; j < n; j++){
			int mid = Table[i - 1][j];
			if (mid != -1){
				Table[i][j] = Table[i - 1][mid];
				minEdge[i][j] = min(minEdge[i - 1][j], minEdge[i - 1][mid]);
				maxEdge[i][j] = max(maxEdge[i - 1][j], maxEdge[i - 1][mid]);
			}
		}
	}
}

int walk(int i, int k){
	for (; k && i != -1; k -= LSOne(k)) i = Table[(int)log2(LSOne(k))][i];
	return i;
}

int lca(int u, int v){
	if (Depth[u] < Depth[v]) v = walk(v, Depth[v] - Depth[u]);
	if (Depth[v] < Depth[u]) u = walk(u, Depth[u] - Depth[v]);
	if (u == v) return u;

	for (int d = D; d >= 0; d--){
		if (Table[d][u] != Table[d][v]){
			u = Table[d][u];
			v = Table[d][v];
		}
	}
	return Table[0][u];
}

int min_query(int u, int v){
	int res = 0x3f3f3f3f;
	int LCA = lca(u, v);
	int k = Depth[u] - Depth[LCA];
	for (; k && u != -1; k -= LSOne(k)){
		res = min(res, minEdge[(int)log2(LSOne(k))][u]);
		u = walk(u, LSOne(k));
	}
	k = Depth[v] - Depth[LCA];
	for (; k && v != -1; k -= LSOne(k)){
		res = min(res, minEdge[(int)log2(LSOne(k))][v]);
		v = walk(v, LSOne(k));
	}
	return res;
}

int max_query(int u, int v){
	int res = 0;
	int LCA = lca(u, v);
	int k = Depth[u] - Depth[LCA];
	for (; k && u != -1; k -= LSOne(k)){
		res = max(res, maxEdge[(int)log2(LSOne(k))][u]);
		u = walk(u, LSOne(k));
	}
	k = Depth[v] - Depth[LCA];
	for (; k && v != -1; k -= LSOne(k)){
		res = max(res, maxEdge[(int)log2(LSOne(k))][v]);
		v = walk(v, LSOne(k));
	}
	return res;
}
