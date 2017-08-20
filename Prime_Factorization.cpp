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

vector< pair<int,int> > Factorization(int num){
	vector< pair<int,int> > vp;
	int i = 0, prime = primes[i];
	while(i < primes.size() && num != 1){
		int cnt = 0;
		while(num % prime == 0) {
			cnt++;
			num /= prime;
		}
		if(cnt) vp.push_back({prime,cnt});
		prime = primes[++i];
	}
	return vp;
}

int main(){
	int num;
	Sieve();
	scanf("%d",&num);
	vector< pair<int,int> > vp = Factorization(num);
	for(int i = 0; i < vp.size(); i++) printf("%d %d\n", vp[i].first, vp[i].second);
	return 0;
}




