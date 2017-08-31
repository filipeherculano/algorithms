#include <bits/stdc++.h>
#define maxn 11111

using namespace std;

int n, m, p[maxn];

int father(int i){
	if(p[i] == i) return i;
	return p[i] = father(p[i]);
}

void join(int i, int j){
	int pi = father(i), pj = father(j);
	if(pi != pj) p[max(pi,pj)] = min(pi,pj);
}

int main(){
	for(int i = 0; i < n; i++) p[i] = i;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		join(a,b);
	}
	return 0;
}
