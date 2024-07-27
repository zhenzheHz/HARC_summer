//Author : Zhenzhe
//Time : 2024/07/26(Fri)
//Problem : https://codeforces.com/contest/1996/problem/A
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int n;cin>>n;
    int ans = n/4 + (n%4)/2;
    cout << ans << '\n';
}
int32_t main(){
    FASTIO;
    int test = 1;
    cin >> test;
    while(test--){
        solve();
    }
}
