#include <bits/stdc++.h>
#define maxn 1111

using namespace std;

const double EPS = 1e-6;

int n,m,adj[maxn][maxn];

int main(){
	memset(adj,0x3f3f3f3f,sizeof adj);
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		adj[a][b] = w;
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
			}
		}
	}
	return 0;
}
