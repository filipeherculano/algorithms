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














