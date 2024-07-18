//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1955/problem/G
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    pair<int,int> dp[n][m];
    #define ff first
    #define ss second
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        cin >> mat[i][j];
    }
    dp[0][0].ff = dp[0][0].ss = mat[0][0];
    for(int i=1;i<n;i++){
        int val = __gcd(dp[i-1][0].ff,mat[i][0]);
        dp[i][0] = {val,val};
    }
    for(int j=1;j<m;j++){
        int val = __gcd(dp[0][j-1].ff,mat[0][j]);
        dp[0][j] = {val,val};
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int top = max(__gcd(dp[i-1][j].ff,mat[i][j]),__gcd(dp[i-1][j].ss,mat[i][j]));
            int left = max(__gcd(dp[i][j-1].ff,mat[i][j]),__gcd(dp[i][j-1].ss,mat[i][j]));
            dp[i][j] = {top,left};
        }
    }
    cout << max(dp[n-1][m-1].ff,dp[n-1][m-1].ss) << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
