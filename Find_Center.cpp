#include <bits/stdc++.h>
#define maxn 111111

using namespace std;

const double EPS = 1e-6;

int n, Degree[maxn];
vector<int> adj[maxn];
bool vis[maxn];

int Find_Center(){
	queue<int> fila[2];
	for(int i = 0; i < n; i++){
		if(Degree[i] == 1){
			fila[0].push(i);
		}
	}
	int cnt = 0, turn = 0;
	while(cnt+2 < n){
		while(!fila[turn].empty()){
			int u = fila[turn].front(); fila[turn].pop();
			vis[u] = true;
			cnt++;
			for(int i = 0; i < adj[u].size(); i++){
				if(!vis[adj[u][i]]){
					Degree[adj[u][i]]--;
					if(Degree[adj[u][i]] == 1) fila[1-turn].push(adj[u][i]);
				}
			}
		}
		turn = 1-turn;
	}
	printf("Center(s):");
	for(int i = 0; i < n; i++){
		if(!vis[i]) printf(" %d", i+1);
	} puts("");
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n-1; i++){
		int a,b;
		scanf("%d %d",&a,&b); a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		Degree[a]++;
		Degree[b]++;
	}
	Find_Center();
	return 0;
}













