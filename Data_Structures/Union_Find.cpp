/**
 * @file Union_Find.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-09
 */
#define maxn 11111

int p[maxn];

int father(int i){
	if(p[i] == i) return i;
	return p[i] = father(p[i]);
}

void join(int i, int j){
	int pi = father(i), pj = father(j);
	if(pi != pj) p[max(pi,pj)] = min(pi,pj);
}

void build(){
	for(int i = 0; i < maxn; ++i)
		p[i] = i;
}