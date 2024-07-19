//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1926/problem/C
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(vector<int> &dp){
    int n;cin>>n;
    cout << dp[n] << '\n';
}
int32_t main(){
    FASTIO;

    vector<int> dp(2e5+5,0);
    for(int i=1;i<=2e5;i++){
        int cnt = 0;
        string x = to_string(i);
        for(char &i : x)cnt += (i-'0');
        dp[i] = dp[i-1] + cnt;
    }

    int test;
    cin >> test;
    while(test--){
        solve(dp);
    }
}
