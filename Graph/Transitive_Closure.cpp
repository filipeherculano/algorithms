/**
 * @file Transitive_Closure.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#include <bits/stdc++.h>
#define maxn 1111

using namespace std;

int n,m,adj[maxn][maxn];

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a][b] = 1;
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				adj[i][j] |= adj[i][k] & adj[k][j];
			}
		}
	}
	return 0;
}
