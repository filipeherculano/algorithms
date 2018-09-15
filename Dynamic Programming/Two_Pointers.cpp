/**
 * @file Two_Pointers.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-08-20
 */
#define maxn 111111

using namespace std;

int n, target, arr[maxn];

int main(){
    cin >> n >> target;
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    int l = 0, r = 0, current = 0;
    bool found = false;
    while(r < n && !found){
        if(current + arr[r] > target){
            l++;
            r = max(l,r);
        } else if(current + arr[r] < target){
            current += arr[r];
            r++;
        } else found = true;
    }

    if(found) puts("Yes");
    else puts("No");
    return 0;     
}