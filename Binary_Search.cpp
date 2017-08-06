#include <bits/stdc++.h>
#define maxn 11111

using namespace std;

const double EPS = 1e-6;

int n;
int array_int[maxn];
double array_double[maxn];

int binary_search(int num){
	int l = 0, r = n-1, b;
	while(l <= r){
		b = (l+r)/2;
		if(array_int[b] == num) return b;
		else if(array_int[b] < num) l = b+1;
		else r = b-1;
	}
	return -1;
}

int binary_search_double(double num){
	int l = 0, r = n-1, b;
	for(int i = 0; i < 200; i++){
		b = (l+r)/2;
		if(abs(array_double[b]-num) < EPS) return b;
		else if(array_double[b] < num) l = b;
		else r = b;
	}
	return -1;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d", &array_int[i]);
	//for(int i = 0; i < n; i++) scanf("%d", &array_double[i]);
	//sort(array_int, array_int+n);
	return 0;
}
