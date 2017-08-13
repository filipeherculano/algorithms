#include <bits/stdc++.h>
#define maxn 11111
#define ii pair<int,int>

using namespace std;

const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;

int n,m;
vector<int> adj[maxn];
queue<int> ts;
bool vis[maxn];

void dfs(int i){
	vis[i] = true;
	for(int j = 0; j < adj[i].size(); j++){
		if(!vis[adj[i][j]]){
			dfs(adj[i][j]);
		}
	}
	ts.push(i);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a,b;
		scanf("%d %d",&a, &b);
		adj[a].push_back(b);
	}
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	return 0;
}
