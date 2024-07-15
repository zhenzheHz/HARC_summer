//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T>
void see(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void saw(T&&... args) { ((cerr << args << " "), ...);}
int32_t main(){
    string DNA;
    cin >> DNA;
    int ans = 1;//DNA[0]
    int tmp = 1;
    for(int i=1;i<DNA.length();i++){
        if(DNA[i] == DNA[i-1]){
            tmp += 1;
        }else tmp = 1;
        ans = max(ans,tmp);
    }
    see(ans);
}
