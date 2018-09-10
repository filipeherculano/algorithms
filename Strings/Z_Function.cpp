/**
 * @file Z_Function.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 1111111

using namespace std;

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

int build(){
	cin >> pattern >> text;
	n = text.size();
	m = pattern.size();
	join = pattern + "#" + text;
	Z_Function();
	for(int i = 0; i < join.size(); i++) 
		if(z[i] == m)
			printf("Match at %d \n", i-m-1);
	return 0;
}






