#include <bits/stdc++.h>
#define maxn 1111111

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

int main(){
	int num;
	vector< pair<int,int> > Prime_Factor;
	scanf("%d",&num);
	for(int i = 2; i*i <= num; i++){
		int cnt = 0;
		while(num % i == 0){
			cnt++;
			num /= i;
		}
		if(cnt) Prime_Factor.push_back({cnt,i});
	}
	if(num != 1) Prime_Factor.push_back({1,num});
	for(int i = 0; i < (int)Prime_Factor.size(); i++){
		printf("%d %d\n", Prime_Factor[i].first, Prime_Factor[i].second);
	}
	return 0;
}




