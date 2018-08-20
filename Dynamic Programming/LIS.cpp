/**
 * @brief This code implements a simple example of the Longest Increasing
 * Subsequence (LIS), in O(N * log N) complexity.
 * 
 * @file LIS.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-19
 */
#include <bits/stdc++.h>
#define maxn 1111111

using namespace std;

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
