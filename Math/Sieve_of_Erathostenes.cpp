/**
 * @file Sieve_of_Erathostenes.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-06
 */
#define maxn 1111111

using namespace std;

bool is_prime[maxn];
vector<int> primes;

void Sieve(){
	memset(is_prime,true,sizeof is_prime);
	is_prime[0] = is_prime[1] = false;
	for(long long i = 2; i < maxn; i++){
		if(is_prime[i]){
			for(long long j = i*i; j < maxn; j += i)
				is_prime[j] = false;
			primes.push_back(i);
		}
	}
}