//Author : Zhenzhe
//Time : 2024/07/27(Sun)
//Problem : https://codeforces.com/contest/1992/problem/C
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=n;i>=k;i--){
        cout << i << ' ';
    }
    for(int i=k-1;i>m;i--){
        cout << i << ' ';
    }
    for(int i=1;i<=m;i++){
        cout << i << ' ';
    }
    cout << '\n';
}
int32_t main(){
    FASTIO;
    int test = 1;
    cin >> test;
    while(test--){
        solve();
    }
}
