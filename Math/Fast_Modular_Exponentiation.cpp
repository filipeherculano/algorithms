#include <bits/stdc++.h>
#define maxn 11111
#define ii pair<int,int>

using namespace std;

const double EPS = 1e-6;
const int mod = 1e9+7;

long long fast_mod_exp(long long b, long long exp){
	long long res = 1;
	while(exp){
		if(exp&1) res = (res * b) % mod;
		b = (b * b) % mod;
		exp /= 2;
	}
	return res;
}

int main(){
	long long b,exp;
	scanf("%lld %lld",&b,&exp);
	printf("%lld\n", fast_mod_exp(b,exp));
	return 0;
}
