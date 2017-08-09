#include <bits/stdc++.h>
#define maxn 11111

using namespace std;

const double EPS = 1e-6;

int n, Prefix_Sum[maxn];

int query(int l, int r){
	return Prefix_Sum[r] - (l == 0 ? 0:Prefix_Sum[l-1]);
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&Prefix_Sum[i]);
	for(int i = 1; i < n; i++) Prefix_Sum[i] += Prefix_Sum[i-1]; 
	return 0;
}
