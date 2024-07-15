//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1070
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T>
void see(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void saw(T&&... args) { ((cerr << args << "\n"), ...);}
int32_t main(){
    int n;cin>>n;
    if(n==1)see(1);
    else if(n<=3)see("NO SOLUTION");
    else{
        for(int i=2;i<=n;i+=2)
            see(i);
        for(int i=1;i<=n;i+=2)
            see(i);
    }
}
