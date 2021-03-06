/**
 * @file Needleman-Wunsch_Edit_Distance.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
using namespace std;

int n,m;
string a,b;

int EditDistance(){
	cin >> a >> b;
	n = a.size();
	m = b.size();
	int pd[n+1][m+1]; memset(pd,63,sizeof pd);
	pd[0][0] = 0;
	for(int j = 1; j <= m; j++) pd[0][j] = j;
	for(int i = 1; i <= n; i++) pd[i][0] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			pd[i][j] = min(pd[i][j], 1+pd[i-1][j]);
			pd[i][j] = min(pd[i][j], 1+pd[i][j-1]);
			pd[i][j] = min(pd[i][j],(a[i-1] == b[j-1] ? 0:1)+pd[i-1][j-1]);
		} 
	} 
	return pd[n][m];
}
