/**
 * @file LCA_SegTree.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 1111111

using namespace std;

int n, q,depth[maxn], SegTree[4*maxn], rep[maxn];
vector<int> adj[maxn], Linear_Tree;

void Tree_Linearization(int i, int p, int d){
	depth[i] = d;
	rep[i] = Linear_Tree.size();
	Linear_Tree.push_back(i);
	for(int j = 0; j < adj[i].size(); j++){
		if(p != adj[i][j]){
			Tree_Linearization(adj[i][j], i, d+1);
			Linear_Tree.push_back(i);
		}
	}
}

void build(int p, int L, int R){
	if(L == R) SegTree[p] = Linear_Tree[L];
	else {
		int mid = (L+R)/2;
		build(p << 1, L, mid);
		build((p << 1)+1, mid+1, R);
		int p1 = SegTree[p << 1], p2 = SegTree[(p << 1)+1];
		SegTree[p] = (depth[p1] < depth[p2] ? p1:p2);
	}
}

int lca(int p, int i, int j, int L, int R){
	if(R < i || j < L) return -1;
	if(i <= L && R <= j) return SegTree[p];
	
	int mid = (L+R)/2;
	int p1 = lca(p << 1,i,j, L, mid);
	int p2 = lca((p << 1)+1,i,j, mid+1, R);
	
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	
	return (depth[p1] < depth[p2] ? p1:p2);
}

int main(){
	Tree_Linearization(1,-1,0); // rooted at 1
	build(1,0,Linear_Tree.size()-1);
	for(int i = 0; i < q; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d = %d\n",a,b,lca(1,min(rep[a],rep[b]),max(rep[a],rep[b]),0,Linear_Tree.size()-1));
	}
	return 0;
}
