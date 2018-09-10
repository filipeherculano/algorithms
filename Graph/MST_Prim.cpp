/**
 * @file MST_Prim.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-14
 */
#include <bits/stdc++.h>
#define maxn 111111

using namespace std;

int mst;
vector<int> adj[maxn], wadj[maxn];
priority_queue< pair<int,int> > pq;
bool vis[maxn];

void process(int u){
    vis[u] = true;
    for(int j = 0; j < adj[u].size(); j++)
        if(!vis[adj[u][j]]) 
            pq.push({-wadj[u][j],adj[u][j]});
}

void Prim(){
    process(0);
    while(!pq.empty()) {
        int u = pq.top().second, w = -pq.top().first;
        pq.pop();
        if(!vis[u]) mst += w, process(u);
    }
}