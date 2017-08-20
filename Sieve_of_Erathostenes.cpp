#include <bits/stdc++.h>
#define maxn 1111111

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

bool is_prime[maxn];
vector<int> primes;

void Sieve(){
	memset(is_prime,true,sizeof is_prime);
	is_prime[0] = is_prime[1] = false;
	for(long long i = 2; i < maxn; i++){
		if(is_prime[i]){
			for(long long j = i*i; j < maxn; j += i){
				is_prime[j] = false;
			}
			primes.push_back(i);
		}
	}
}

int main(){
	Sieve();
	for(int i = 0; i < primes.size(); i++) cout << primes[i] << " "; puts("");
	return 0;
}
