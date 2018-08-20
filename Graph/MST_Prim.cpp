/**
 * @brief 
 * 
 * @file MST_Prim.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-14
 */
#include <bits/stdc++.h>
#define maxn 111111

using namespace std;

int n, m, mst;
vector<int> adj[maxn], wadj[maxn];
priority_queue< pair<int,int> > pq;
bool vis[maxn];

void process(int u){
    vis[u] = true;
    for(int j = 0; j < adj[u].size(); j++){
        if(!vis[adj[u][j]]) 
            pq.push({-wadj[u][j],adj[u][j]});
    }
}

void Prim(){
    process(0);
    while(!pq.empty()) {
        int u = pq.top().second, w = -pq.top().first;
        pq.pop();
        if(!vis[u]) mst += w, process(u);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a,b,w;
        scanf("%d %d %d", &a, &b, &w);
        adj[a].push_back(b); wadj[a].push_back(w);
        adj[b].push_back(a); wadj[b].push_back(w);
    }
    Prim();
    cout << mst << endl;
    return 0;
}