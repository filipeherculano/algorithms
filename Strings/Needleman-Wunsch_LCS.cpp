/**
 * @file Needleman-Wunsch_LCS.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
using namespace std;

int n,m;
string a,b;

int lcs(){
	cin >> a >> b;
	n = a.size();
	m = b.size();
	int pd[n+1][m+1];
	memset(pd,0,sizeof pd);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			pd[i][j] = max(pd[i][j], pd[i-1][j]);
			pd[i][j] = max(pd[i][j], pd[i][j-1]);
			pd[i][j] = max(pd[i][j],(a[i-1] == b[j-1] ? 1:-INF)+pd[i-1][j-1]);
		} 
	}
	return pd[n][m];
}
