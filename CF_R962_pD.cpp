// Author : Zhenzhe
// Time : 2024/07/26
// Problem : https://codeforces.com/contest/1996/problem/D
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int n,x,sum = 0;
    cin >> n >> x;
    for(int a=1;a<=x-2;a++){
        for(int b=1;b<=x-a-1;b++){
            if(a*b>=n)break;
            int c = (n-a*b)/(a+b);
            sum += min(c,x-a-b);
        }
    }
    cout << sum << '\n';
}
int32_t main(){
    //FASTIO;
    int test = 1;
    cin >> test;
    while(test--){
        solve();
    }
}
