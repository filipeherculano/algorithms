#include <bits/stdc++.h>

using namespace std;

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




