#include <bits/stdc++.h>
#define maxn 111111

using namespace std;

const double EPS = 1e-6;

int n, Size[maxn], Parent[maxn];
vector<int> adj[maxn];

int dfs(int i){
	int res = 1;
	for(int j = 0; j < adj[i].size(); j++){
		if(adj[i][j] != Parent[i]){
			Parent[adj[i][j]] = i;
			res += dfs(adj[i][j]);
		}
	}
	return Size[i] = res;
}

int Find_Centroid(int i){
	int next, sz = 0;
	for(int j = 0; j < adj[i].size(); j++){
		if(adj[i][j] != Parent[i]){
			if(sz < Size[adj[i][j]]){
				sz = Size[adj[i][j]];
				next = adj[i][j];
			}
		}
	}
	if(sz > n/2) return Find_Centroid(next);
	return i;
}

int main(){
	memset(Parent,-1,sizeof Parent);
	scanf("%d",&n);
	for(int i = 0; i < n-1; i++){
		int a,b;
		scanf("%d %d",&a,&b); a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	printf("Centroid : %d\n", Find_Centroid(0)+1);
	return 0;
}
