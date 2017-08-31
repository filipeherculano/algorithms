#include <bits/stdc++.h>

#define LSOne(S) (S & (-S))
#define maxn 1111

using namespace std;

int n,m,BIT[maxn][maxn];

void add(int l, int c, int v){
	for(int k = l; k <= n; k += LSOne(k))
		for(int z = c; z <= m; z += LSOne(z)) 
			BIT[k][z] += v;
}

int query(int l, int c){
	int res = 0;
	for(int k = l; k; k -= LSOne(k))
		for(int z = c; z; z -= LSOne(z)) 
			res += BIT[k][z];
	return res;
}

int rmq(int ux, int uy, int lx, int ly){
	return query(lx,ly)-query(ux-1,ly)-query(lx,uy-1)+query(ux-1,uy-1);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int temp; scanf("%d",&temp);
			add(i,j,temp);
		}
	}
	int ux,uy,lx,ly;
	scanf("%d %d %d %d", &ux,&uy,&lx,&ly);
	cout << rmq(ux,uy,lx,ly) << endl;
	return 0;
}














