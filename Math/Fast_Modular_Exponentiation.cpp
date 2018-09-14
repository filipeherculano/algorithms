/**
 * @file Fast_Modular_Exponentiation.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 11111
#define ll long long
#define ii pair<int,int>

using namespace std;

const int mod = 1e9+7;

ll fast_mod_exp(ll b, ll exp){
	ll res = 1;
	while(exp){
		if(exp&1) res = (res * b) % mod;
		b = (b * b) % mod;
		exp /= 2;
	}
	return res;
}