/**
 * @file LIS.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-19
 */
#define maxn 1111111

using namespace std;

int n,v[maxn];
vector<int> answer;

int LIS(){
	for(int i = 0; i < n; i++){
		int val = distance(answer.begin(), lower_bound(answer.begin(), answer.end(), v[i]));
		if(val == answer.size()) answer.push_back(v[i]);
		else answer[val] = v[i];
	}
	return (int)answer.size();
}
