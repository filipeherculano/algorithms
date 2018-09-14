/**
 * @file Euler_Phi.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-06
 */
using namespace std;

long long euler_phi(long long n){
	long long result = n;
	for(long long i = 2; i*i <= n; i++){
		if(n % i == 0){
			while(n % i == 0) n /= i;
			result -= result/i;
		}
	}
	if(n > 1) result -= result/n;
	return result;
}
// euler_phi(n)/2: Number of relative primes lower then N