/**
 * @file Prefix_Sum_1D.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 11111

using namespace std;

int n, Prefix_Sum[maxn];

int query(int l, int r){
	return Prefix_Sum[r] - (l == 0 ? 0:Prefix_Sum[l-1]);
}

int build(){
	for(int i = 1; i < n; i++) Prefix_Sum[i] += Prefix_Sum[i-1]; 
}
