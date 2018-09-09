/**
 * @file BIT_1D.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define LSOne(S) (S & (-S))
#define maxn 11111

using namespace std;

int BIT[maxn];

void add(int v, int k){
	for(;k < maxn; k += LSOne(k)) BIT[k] += v;
}

int query(int k){
	int res = 0;
	for(;k;k -= LSOne(k)) res += BIT[k];
	return res;
}

int range_query(int i, int j){
	return query(j) - query(i-1);
}