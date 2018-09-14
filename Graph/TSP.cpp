/**
 * @file TSP.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 17

using namespace std;

int n,m,s,TSP[1 << maxn][maxn],mat[maxn][maxn];

int tsp(){
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

	return TSP[(1 << n)-1][s];
}
