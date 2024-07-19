//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1915/problem/A1
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans;
    if(a==b)ans=c;
    else if(a==c)ans=b;
    else ans=a;
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
