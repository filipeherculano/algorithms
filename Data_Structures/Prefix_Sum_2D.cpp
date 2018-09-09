/**
 * @file Prefix_Sum_2D.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 1111

using namespace std;

int n, Prefix_Sum[maxn][maxn];

int query(int ui, int uj, int li, int lj){
	int res = Prefix_Sum[li][lj];
	res -= (ui == 0 ? 0:Prefix_Sum[ui-1][lj]);
	res -= (uj == 0 ? 0:Prefix_Sum[li][uj-1]);
	res += (ui == 0 || uj == 0 ? 0:Prefix_Sum[ui-1][uj-1]);
	return res;
}

int build(){
	for(int j = 1; j < n; j++) Prefix_Sum[0][j] += Prefix_Sum[0][j-1];
	for(int i = 1; i < n; i++) Prefix_Sum[i][0] += Prefix_Sum[i-1][0];
	for(int i = 1; i < n; i++) 
		for(int j = 1; j < n; j++)
			Prefix_Sum[i][j] += Prefix_Sum[i-1][j] + Prefix_Sum[i][j-1] - Prefix_Sum[i-1][j-1]; 
	return 0;
}
