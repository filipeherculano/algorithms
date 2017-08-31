#include <bits/stdc++.h>
#define maxn 1111111
#define maxnlog 22

using namespace std;

const double EPS = 1e-6;

int n , q,depth[maxn], Sparse_Table[maxnlog][maxn], rep[maxn];
vector<int> adj[maxn];
vector<int> Linear_Tree;

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

void build(int sz){
	for(int i = 0; (1 << i) <= sz; i++){
		for(int j = 0; j+(1 << (i)) <= sz ;j++){
			if(i == 0) Sparse_Table[i][j] = Linear_Tree[j];
			else if(depth[Sparse_Table[i-1][j]] < depth[Sparse_Table[i-1][j+(1 << (i-1))]]) Sparse_Table[i][j] = Sparse_Table[i-1][j];
			else Sparse_Table[i][j] = Sparse_Table[i-1][j+(1 << (i-1))];
		}
	}
}

int lca(int a, int b){
	int i = log2(b-a+1);
	return (depth[Sparse_Table[i][a]] < depth[Sparse_Table[i][b-(1 << i)+1]] ? Sparse_Table[i][a]:Sparse_Table[i][b-(1 << i)+1]);
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i = 0; i < n-1; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	Tree_Linearization(1,-1,0); // rooted at 1
	build(Linear_Tree.size());
	for(int i = 0; i < q; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d = %d\n",a,b,lca(min(rep[a],rep[b]),max(rep[a],rep[b])));
	}
	return 0;
}
