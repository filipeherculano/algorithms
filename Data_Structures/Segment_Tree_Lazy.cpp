#include <bits/stdc++.h>
#define maxn 11111

using namespace std;

int n, segtree_base[maxn], segtree[4*maxn], lazy[4*maxn];

void build(int p, int L, int R){
	if(L == R) segtree[p] = segtree_base[L];
	else{
		int mid = (L+R)/2;
		build(p << 1, L, mid);
		build((p << 1)+1, mid+1, R);
		segtree[p] = max(segtree[p << 1],segtree[(p << 1)+1]);
	}
}

void update(int p, int i, int j, int L, int R, int val){
	if(lazy[p]){
		segtree[p] += lazy[p];
		if(L != R){
			lazy[p << 1] += lazy[p];
			lazy[(p << 1)+1] += lazy[p];			
		}
		lazy[p] = 0;
	}
	if(j < L || R < i) return;
	if(i <= L && R <= j){
		segtree[p] += val;
		if(L != R){
			lazy[p << 1] += val;
			lazy[(p << 1)+1] += val;			
		}
		return;
	}
	int mid = (L+R)/2;
	update(p << 1, i,j,L,mid,val);
	update((p << 1)+1,i,j,mid+1,R,val);
	segtree[p] = max(segtree[p << 1],segtree[(p << 1)+1]);
}

int rmq(int p, int i, int j, int L, int R){
	if(j < L || R < i) return -1;
	if(lazy[p]){
		segtree[p] += lazy[p];
		if(L != R){
			lazy[p << 1] += lazy[p];
			lazy[(p << 1)+1] += lazy[p];			
		}
		lazy[p] = 0;
	}
	if(i <= L && R <= j) return segtree[p];

	int mid = (L+R)/2;
	int p1 = rmq(p << 1, i, j, L, mid);
	int p2 = rmq((p << 1)+1, i, j, mid+1, R);
	
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	
	return max(p1,p2);
}

int main(){
	scanf("%d",&n); for(int i = 0; i < n; i++) scanf("%d",&segtree_base[i]);
	build(1,0,n-1); return 0;
}
