/**
 * @brief This program is an example of the Two Pointer technique,
 * used to solve Subarray Sum problem in O(n) 
 * 
 * @file Two_Pointers.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-20
 */
#include <bits/stdc++.h>
#define maxn 111111

using namespace std;

int n, target, arr[maxn];

int maint(){
    cin >> n >> target;
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    int l = 0, r = 0, current = 0;
    while(l < n){
        if(r < n){
            
        }
        if(r < n && current + arr[r] > target){
            
        }
    }
    return 0;     
}