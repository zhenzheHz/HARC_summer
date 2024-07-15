//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1068
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T>
void see(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void saw(T&&... args) { ((cerr << args << " "), ...);}
int32_t main(){
    function<void(int)> deal = [&](int n){
        see(n);
        if(n == 1)return;
        //saw(n);
        if(n&1)deal(3*n+1);
        else deal(n>>1);
    };
    int n;cin>>n;
    deal(n);
}
