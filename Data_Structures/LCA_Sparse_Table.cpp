/**
 * @file LCA_Sparse_Table.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 1111111
#define maxnlog 22

using namespace std;

int depth[maxn], Sparse_Table[maxnlog][maxn], rep[maxn];
vector<int> adj[maxn], Linear_Tree;

void Tree_Linearization(int u, int p, int d){
	depth[u] = d;
	rep[u] = Linear_Tree.size();
	Linear_Tree.push_back(u);
	for(auto & v : adj[u])
		if(p != v)
			Tree_Linearization(v, u, d+1);
	Linear_Tree.push_back(u);
}

void build(int n, int logn){
	for(int i = 0; i <= logn; i++){
		for(int j = 0; j+(1 << (i)) <= n ;j++){
			if(i != 0){
				int u = Sparse_Table[i-1][j], v = Sparse_Table[i-1][j+(1 << (i-1))];
				if(depth[u] < depth[v]) Sparse_Table[i][j] = u;
				else Sparse_Table[i][j] = v;
			} else Sparse_Table[i][j] = Linear_Tree[j];
		}
	}
}

int lca(int a, int b){
	int i = log2(b-a+1), u = Sparse_Table[i][a], v = Sparse_Table[i][b-(1 << i)+1];
	return (depth[u] < depth[v] ? u:v);
}

void build_environment(){
	Tree_Linearization(0,-1,0); // rooted at 0
	build(Linear_Tree.size(), log2(Linear_Tree.size()));
	// Querie example
	// lca(rep[r], rep[l])
}
