#include <bits/stdc++.h>
#define LSOne(S) (S & (-S))
#define maxn 11111

using namespace std;

const double EPS = 1e-6;

int n,q,BIT[maxn],base[maxn];

void add(int v, int k){
	for(;k <= n; k += LSOne(k)) BIT[k] += v;
}

int query(int k){
	int res = 0;
	for(;k;k -= LSOne(k)) res += BIT[k];
	return res;
}

int range_query(int i, int j){
	return query(j) - (i == 1 ? 0:query(i-1));
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i = 0; i < n; i++) scanf("%d",&base[i]);
	for(int i = 1; i <=n; i++) add(base[i-1],i);
	for(int i = 0; i < q; i++){
		int l,r;
		scanf("%d %d",&l,&r);
		cout << range_query(l,r) << endl;
	}
	return 0;
}
