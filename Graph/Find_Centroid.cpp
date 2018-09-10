/**
 * @file Find_Centroid.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 111111

using namespace std;

int n, Size[maxn];
vector<int> adj[maxn];

int dfs(int u, int p){
	int res = 1;
	for(auto & v : adj[u])
		if(p != v)
			res += dfs(v);
	return Size[i] = res;
}

int Find_Centroid(int u, int p){
	int next, sz = 0;
	for(auto & v : adj[u])
		if(v != p && sz < Size[v]){
			sz = Size[v];
			next = v;
		}
	if(sz > n/2) return Find_Centroid(next, u);
	return i;
}