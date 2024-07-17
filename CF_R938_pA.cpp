//Author : Zhenzhe
//Time : 2024/07/17(Wed)
//Problem :https://codeforces.com/contest/1955/problem/A
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    if(a*2 < b){
        cout << n*a << '\n';
        return;
    }
    int ans = b*(n/2)+a*(n%2);
    cout << ans << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
