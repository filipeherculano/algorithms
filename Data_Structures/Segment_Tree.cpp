/**
 * @file Segment_Tree.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 11111

using namespace std;

int segtree_base[maxn], segtree[4*maxn], rep[maxn];

void build(int p, int L, int R){
	if(L == R) {
		segtree[p] = segtree_base[L];
		rep[L] = p;
	} else{
		int mid = (L+R)/2;
		build(p << 1, L, mid);
		build((p << 1)+1, mid+1, R);
		segtree[p] = max(segtree[p << 1],segtree[(p << 1)+1]);
	}
}

int rmq(int p, int i, int j, int L, int R){
	if(j < L || R < i) return -1;
	if(i <= L && R <= j) return segtree[p];
	int mid = (L+R)/2;
	int p1 = rmq(p << 1, i, j, L, mid);
	int p2 = rmq((p << 1)+1, i, j, mid+1, R);
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	return max(p1,p2);
}

void point_update(int u, int v){
	if(u == 0) return;
	segtree[u] = max(segtree[u], v);
	point_update(u/2,v);
}