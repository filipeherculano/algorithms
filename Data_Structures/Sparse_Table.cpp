/**
 * @file Sparse_Table.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 1111111
#define maxnlog 22

using namespace std;

// We can use to do range queries (max,min,gcd,lcm,LCA)
int n, Sparse_Table[maxnlog][maxn];

void build(){
	for(int i = 1; (1 << i) <= n; i++){
		for(int j = 0; j + (1 << i) <= n; j++){
			Sparse_Table[i][j] = 
				max(Sparse_Table[i-1][j],Sparse_Table[i-1][j+(1 << (i-1))]);
		}
	}
}

int range_query(int i, int j){
	int sz = log2(j-i+1);
	return max(Sparse_Table[sz][i],Sparse_Table[sz][j+1-(1 << sz)]);
}