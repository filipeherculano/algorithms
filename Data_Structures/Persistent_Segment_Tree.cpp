/**
 * @file Persistent_Segment_Tree.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 2000000

int n, next_node;
int esq[30*maxn],dir[30*maxn],st[30*maxn],root[30*maxn],base[maxn];

int build(int L, int R){
	int p = next_node++;
	if(L == R) st[p] = base[L];
	else {
		int mid = (L+R)/2;
		esq[p] = build(L,mid);
		dir[p] = build(mid+1,R);
		st[p] = st[esq[p]] + st[dir[p]];
	}
	return p;
}

int update(int old, int L, int R, int pos, int v){
	int p = next_node++;
	if(L == R && L == pos){
		st[p] = v;
		return p;
	}
	int mid = (L+R)/2;
	if(pos <= mid){
		dir[p] = dir[old];
		esq[p] = update(esq[old],L,mid,pos,v);
	} else {
		dir[p] = update(dir[old],mid+1,R,pos,v);
		esq[p] = esq[old];
	}
	st[p] = st[esq[p]] + st[dir[p]];
	return p;
}

int query(int p, int L, int R, int i, int j){
	if(L > j || R < i) return 0;
	if(i <= L && R <= j) return st[p];
	int mid = (L+R)/2;
	int p1 = query(esq[p],L,mid,i,j);
	int p2 = query(dir[p],mid+1,R,i,j);
	return p1+p2;
}
