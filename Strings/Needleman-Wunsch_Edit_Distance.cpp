#include <bits/stdc++.h>

using namespace std;

int n,m;
string a,b;

int main(){
	cin >> a >> b;
	n = a.size();
	m = b.size();
	int pd[n+1][m+1]; memset(pd,0x3f3f3f3f,sizeof pd);
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
	cout << pd[n][m] << endl;
	return 0;
}
