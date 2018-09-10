/**
 * @file TSP.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#include <bits/stdc++.h>
#define maxn 17

using namespace std;

int n,m,s,TSP[1 << maxn][maxn],mat[maxn][maxn];

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		mat[a][b] = mat[b][a] = w;
	}
	scanf("%d",&s);
	memset(TSP,0x3f3f3f3f, sizeof TSP);
	TSP[0][s] = 0; // zero on the origin
	
	for(int bit = 0; bit < (1 << n); bit++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(bit&(1 << i) && !(bit&(1 << j))){
					TSP[bit | (1 << j)][j] = min(TSP[bit | (1 << j)][j], TSP[bit][i]+mat[i][j]);
				}
			}
		}
	}
	cout << TSP[(1 << n)-1][s] << endl;
	return 0;
}
