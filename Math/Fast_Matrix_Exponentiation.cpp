/**
 * @file Fast_Matrix_Exponentiation.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 1111

using namespace std;

int n, e, mat[maxn][maxn], r[maxn][maxn];

void mult(bool isOdd){
	int aux[n][n]; memset(aux,0,sizeof aux);
	if(isOdd){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					aux[i][j] += (mat[i][k] * r[k][j]);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				r[i][j] = aux[i][j]; 
	} else {
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					aux[i][j] += (mat[i][k] * mat[k][j]);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				mat[i][j] = aux[i][j]; 
	}
}

void fast_matrix_exp(){
	while(e){
		if(e&1) mult(true);
		mult(false);
		e /= 2;
	}
}
