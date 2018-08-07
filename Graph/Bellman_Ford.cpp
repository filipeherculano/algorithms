#include <bits/stdc++.h>
#define maxn 100000
#define INF 0x3f3f3f3f

using namespace std;

int n,m,dist[maxn];
vector< tuple<int,int,int> > edges;

void bellman_ford(int s){
	memset(dist,INF,sizeof dist);
	dist[s] = 0;
	for(int i = 0; i < n-1; i++){
		for(auto e : edges){
			int a,b,w;
			tie(a,b,w) = e;
			dist[b] = min(dist[b], dist[a] + w);
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		int a,b,w; 
		scanf("%d %d %d",&a,&b,&w);
		edges.push_back(make_tuple(a,b,w));
	}
	bellman_ford(0);	
	for(int i = 0; i < n; i++) cout << dist[i] << endl;
	return 0;
}

















