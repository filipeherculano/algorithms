/**
 * @file Huffman_Coding.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-19
 */
#define maxn 333
#define ii pair<int,int>

using namespace std;

string s; // Input must be lower case letters from 'a' to 'z'
int n, cur, bucket[26];
bool vis[maxn];
vector<int> tree[maxn];
map<char,string> encript;
priority_queue<ii, vector<ii>, greater<ii> > pq;

void dfs(int u, string bitmask){
    vis[u] = true;
    if(tree[u].size() == 0) {
        reverse(bitmask.begin(), bitmask.end());
        encript[u+'a'] = bitmask;
        return;
    }

    dfs(tree[u][0], bitmask + '0');
    dfs(tree[u][1], bitmask + '1');
    return;
}

int build(){
    cur = 26;
    cin >> n >> s;
    for(int i = 0; i < n; i++) bucket[s[i]-'a']++;
    for(int i = 0; i < 26; i++) if(bucket[i]) pq.push({bucket[i], i});
    while(pq.size() != 1){
        ii a = pq.top(); pq.pop();
        ii b = pq.top(); pq.pop();
        if(a.first <= b.first) {
            tree[cur].push_back(b.second);
            tree[cur].push_back(a.second);
        } else {
            tree[cur].push_back(a.second);
            tree[cur].push_back(b.second);
        }
        pq.push({(a.first + b.first), cur++});
    }
    dfs(cur-1,"");
}
