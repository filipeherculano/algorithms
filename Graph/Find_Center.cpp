/**
 * @file Find_Center.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 111111

using namespace std;

int n, Degree[maxn];
vector<int> adj[maxn];
bool vis[maxn];

int Find_Center(){
	queue<int> fila[2];
	for(int i = 0; i < n; i++)
		if(Degree[i] == 1)
			fila[0].push(i);

	int cnt = 0, turn = 0;
	while(cnt+2 < n){
		while(!fila[turn].empty()){
			int u = fila[turn].front(); fila[turn].pop();
			vis[u] = true;
			cnt++;
			for(auto & v : adj[u])
				if(!vis[v]){
					Degree[v]--;
					if(Degree[v] == 1)
						fila[1-turn].push(v);
				}
		}
		turn = 1-turn;
	}
}