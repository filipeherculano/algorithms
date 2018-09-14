/**
 * @file Floyd_Warshall.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 1111

using namespace std;

int n,adj[maxn][maxn];

void build(){
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}
