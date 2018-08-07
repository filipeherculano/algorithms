/**
 * @brief A simple two faced algorithm. Show a simple application of
 * the Euclidean Algorithm to generate GCD and LCM.
 * 
 * @file GCD_and_LCM.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-04
 */
#include <bits/stdc++.h>

using namespace std;

// Greatest Common Divisor
int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}

// Lowest Common Multiplier
int lcm(int a, int b){
    return (a / gcd(a,b)) * b;
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    cout << gcd(max(a,b), min(a,b)) << endl;
    cout << lcm(max(a,b), min(a,b)) << endl;
    return 0;
}