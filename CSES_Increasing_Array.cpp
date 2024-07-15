//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T>
void see(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void saw(T&&... args) { ((cerr << args << "\n"), ...);}
int32_t main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int &i : a)cin>>i;
    int pre=a[0],ans=0;
    for(int i=1;i<n;i++){
        if(a[i] < pre){
            ans += pre-a[i];
            a[i] = pre;
        }
        pre = a[i];
    }
    see(ans);
}
