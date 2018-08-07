#include <bits/stdc++.h>

using namespace std;

int Extended_Euclidean(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1;
    int d = Extended_Euclidean(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}

int main(){
    int a,b,x,y;
    scanf("%d %d", &a, &b);
    Extended_Euclidean(a,b,x,y);
    return 0;
}