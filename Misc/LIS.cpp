#include <bits/stdc++.h>
#define maxn 1111111

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

int n,v[maxn];
vector<int> answer;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&v[i]);
	for(int i = 0; i < n; i++){
		int val = distance(answer.begin(), lower_bound(answer.begin(), answer.end(), v[i]));
		if(val == answer.size()) answer.push_back(v[i]);
		else answer[val] = v[i];
	}
	printf("%d\n", (int)answer.size());
	return 0;
}
