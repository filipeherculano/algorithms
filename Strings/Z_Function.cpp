#include <bits/stdc++.h>
#define maxn 1111111

using namespace std;

const double EPS = 1e-6;

int n,m,z[maxn];
string text, pattern, join;

void Z_Function(){
	int L = 0, R = 0;
	for(int i = 1; i < join.size(); i++){
		if(i > R){
			L = R = i;
			while(R < join.size() && join[R-L] == join[R]) R++;
			z[i] = R-L; R--;
		} else {
			int k = i-L;
			if(i+z[k] <= R) z[i] = z[k];
			else {
				L = i;
				while(R < join.size() && join[R-L] == join[R]) R++;
				z[i] = R-L; R--;
			}
		}
	}
}

int main(){
	cin >> pattern >> text;
	n = text.size();
	m = pattern.size();
	join = pattern + "#" + text;
	Z_Function();
	for(int i = 0; i < join.size(); i++) {
		if(z[i] == m){
			printf("Match at %d \n", i-m-1);
		}
	}
	return 0;
}






