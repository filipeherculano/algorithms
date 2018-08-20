#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n,m;
string a,b;

int main(){
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
	cout << pd[n][m] << endl;
	return 0;
}
