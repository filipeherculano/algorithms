/**
 * @file SCC_Kosaraju.cpp
 * @author your name
 * @date 2018-09-14
 */
#define maxn 200000

using namespace std;

int color[maxn],scc;
vector<int> pos_order, adj[2][maxn];
bool vis[maxn];

void dfs(int u, int turn){
    vis[u] = true;
    for(auto & v : adj[turn][u])
        if(!vis[v])
            dfs(v,turn);
    if(turn == 0) pos_order.push_back(u);
    else color[u] = scc;
}

void kosaraju(){
    memset(vis,false,sizeof vis);
    for(int i = 0 ; i < n; i++)
        if(!vis[i])
            dfs(i,0);
    memset(vis,false,sizeof vis);
    for(int i = pos_order.size()-1; i >= 0; i--){
        if(!vis[pos_order[i]]){
            ++scc;
            dfs(pos_order[i],1);
        }
    }
}