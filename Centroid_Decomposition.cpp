#include <bits/stdc++.h>
#define maxn 111111
#define LSOne(S) (S & (-S))

using namespace std;

const double EPS = 1e-6;

int n, Centroid_Tree[maxn], Size[maxn];
vector<int> adj[maxn];
bool cut[maxn];

int dfs(int i, int p){
	int res = 1;
	for(int j = 0; j < adj[i].size(); j++){
		if(!cut[adj[i][j]] && adj[i][j] != p){
			res += dfs(adj[i][j], i);
		}
	}
	return Size[i] = res;
}

int Find_Centroid(int i, int p, int tot){
	int next, cnt = 0;
	for(int j = 0; j < adj[i].size(); j++){
		if(!cut[adj[i][j]] && adj[i][j] != p && cnt < Size[adj[i][j]]){
			cnt = Size[adj[i][j]];
			next = adj[i][j];
		}
	}
	if(cnt > tot/2) return Find_Centroid(next,i,tot);
	return i;
}

void build(int i, int p){
	dfs(i,-1);
	int u = Find_Centroid(i, -1, Size[i]);
	cut[u] = true;
	Centroid_Tree[u] = p;
	for(int j = 0; j < adj[u].size(); j++){
		if(!cut[adj[u][j]]){
			build(adj[u][j], u);
		}
	}
}

int main(){
	memset(Centroid_Tree,-1, sizeof Centroid_Tree);
	
	scanf("%d",&n);
	for(int i = 0; i < n-1; i++){
		int a,b;
		scanf("%d %d",&a,&b); a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(0,-1);
	return 0;
}
