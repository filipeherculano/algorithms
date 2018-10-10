/**
 * @file Trie.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
using namespace std;

vector< pair<vector<int>, int> > Trie;

void add(string a){
	int node = 0;
	for(int i = 0; i < (int)a.size(); i++){
		Trie[node].second++;
		int nxt = a[i]-'a';
		if(Trie[node].first[nxt] == 0) {
			vector<int> v(26,0);
			Trie[node].first[nxt] = Trie.size();
			Trie.push_back({v,0});
		}
		node = Trie[node].first[nxt];
	}
	Trie[node].second++;
}

void rmv(string a){
	int node = 0;
	Trie[node].second--;
	for(int i = 0; i < (int)a.size(); i++){
		int nxt = a[i]-'a';
		node = Trie[node].first[nxt];
		Trie[node].second--;
	}
}

bool query(string a){
	int node = 0;
	for(int i = 0; i < (int)a.size(); i++){
		int nxt = a[i]-'a';
		if(Trie[node].first[nxt] && Trie[Trie[node].first[nxt]].second) 
			node = Trie[node].first[nxt];
		else return false;
	}
	return true;
}

void build(){
	vector<int> root(26,0);
	Trie.push_back({root,0});
}
