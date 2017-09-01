#include <bits/stdc++.h>

using namespace std;

int n,m,cur;
string s;
vector< pair<vector<int>, int> > Trie;

void add(string a){
	int d = 0;
	Trie[d].second++;
	for(int i = 0; i < (int)a.size(); i++){
		int c = a[i]-'a';
		if(Trie[d].first[c] == 0) {
			vector<int> v(26,0);
			Trie[d].first[c] = cur++;
			Trie.push_back({v,0});
		}
		d = Trie[d].first[c];
		Trie[d].second++;
	}
}

void rmv(string a){
	int d = 0;
	for(int i = 0; i < (int)a.size(); i++){
		int c = a[i]-'a';
		Trie[d].second--;
		d = Trie[d].first[c];
	}
	Trie[d].second--;
}

bool query(string a){
	int d = 0;
	for(int i = 0; i < (int)a.size(); i++){
		int c = a[i]-'a';
		if(Trie[d].first[c] && Trie[d].second) d = Trie[d].first[c];
		else return false;
	}
	return Trie[d].second;
}

int main(){
	cur = 1;
	vector<int> v(26,0);
	Trie.push_back({v,0});
	scanf("%d %d%*c",&n,&m);
	for(int i = 0; i < n; i++){
		cin >> s;
		add(s);
	}
	for(int i = 0; i < m; i++){
		cin >> s;
		if(query(s)) puts("Found");
		else puts("Not Found");
	}
	return 0;
}
