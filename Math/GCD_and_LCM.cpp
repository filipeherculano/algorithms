/**
 * @file GCD_and_LCM.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-04
 */
using namespace std;

// Greatest Common Divisor
int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}

// Lowest Common Multiplier
int lcm(int a, int b){
    return (a / gcd(a,b)) * b;
}