#include <bits/stdc++.h>
#define maxn 111111

using namespace std;

const double EPS = 1e-6;

int n, centroid, maxComponent = maxn, Size[maxn], Parent[maxn];
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

void Find_Centroid(){
	for(int i = 0; i < n; i++){
		int comp = 0;
		for(int j = 0; j < adj[i].size(); j++){
			if(adj[i][j] != Parent[i]){
				comp = max(comp, Size[adj[i][j]]);
			}
		}
		comp = max(comp, Size[0]-Size[i]);
		if(maxComponent > comp){
			maxComponent = comp;
			centroid = i;
		}
	}
}

int main(){
	memset(Parent,-1,sizeof Parent);
	scanf("%d",&n);
	for(int i = 0; i < n-1; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	Find_Centroid();
	printf("Centroid : %d\n", centroid);
	printf("Max Component : %d\n", maxComponent);
	return 0;
}
