#include <bits/stdc++.h>

using namespace std;

struct point{
	double x, y;
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct vetor{
	double x, y;
	// direction is from point a -> b	
	vetor(point a, point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
};

struct line{
	double a, b, c;
	// wrong
	line(point A, point B) {
		a = B.y - A.y;
		b = A.x - B.x;
		c = a*A.x + b*A.y;
	}
};

vetor vector_add(vetor A, vetor B){
	vetor res = A;
	res.x += B.x;
	res.y += B.y;
	return res;
}

// dot product: A.B = |A||B|cos(O)
double dot_vet(vetor A, vetor B){
	double res = (A.x*B.x)*(A.y*B.y);
	return res;
}

double dot_point(point a, point b, point c){
	vetor A(b,a);
	vetor B(b,c);
	return dot_vet(A,B);
}

// cross product: AxB = |A||B|sin(O)  
double cross_vet(vetor A, vetor B){
	double res = (A.x*B.y) - (A.y*B.x);
	return res;
}

double cross_point(point a, point b, point c){
	vetor A(b,a);
	vetor B(b,c);
	return cross_vet(A,B);
}

double norm(vetor A){
	return (A.x * A.x) + (A.y * A.y);
}

int main(){
	return 0;
}

