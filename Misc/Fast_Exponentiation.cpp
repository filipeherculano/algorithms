#include <bits/stdc++.h>
#define maxn 11111
#define ii pair<int,int>

using namespace std;

const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;

long long fast_exp(long long b, long long exp){
	long long res = 1;
	while(exp){
		if(exp&1) res *= b;
		b *= b;
		exp /= 2;
	}
	return res;
}

int main(){
	long long b,exp;
	scanf("%lld %lld",&b,&exp);
	printf("%lld\n", fast_exp(b,exp));
	return 0;
}
