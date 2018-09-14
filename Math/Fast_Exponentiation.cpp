/**
 * @file Fast_Exponentiation.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 11111
#define ii pair<int,int>
#define ll long long

using namespace std;

ll fast_exp(ll b, ll exp){
	ll res = 1;
	while(exp){
		if(exp&1) res *= b;
		b *= b;
		exp /= 2;
	}
	return res;
}