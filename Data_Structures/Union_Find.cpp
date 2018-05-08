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
