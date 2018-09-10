/**
 * @file Fast_Exponentiation.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 11111
#define ii pair<int,int>

using namespace std;

long long fast_exp(long long b, long long exp){
	long long res = 1;
	while(exp){
		if(exp&1) res *= b;
		b *= b;
		exp /= 2;
	}
	return res;
}