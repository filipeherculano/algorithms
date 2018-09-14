/**
 * @file Minimax_Maximin.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#include <bits/stdc++.h>
#define maxn 1111

using namespace std;

int n,adj[maxn][maxn];

void minimax(){
	// Minimax
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = min(adj[i][j], max(adj[i][k],adj[k][j]));
}

int maximin(){
	// Maximin
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = max(adj[i][j], min(adj[i][k],adj[k][j]));
}
