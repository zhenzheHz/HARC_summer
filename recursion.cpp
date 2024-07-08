#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int mod = 1e9+7;
int n,m;
int dp[1001][1001]
int divied(int k,int limit){
    if(limit == 0)return 0;
    if(k == 1)return 1;
    if(k == 0)return 0;
    if(dp[k][limit]!=-1)return dp[k][limit];
    dp[k][limit] = (divide(k,limit-1)+divied(k-limit,limit))%mod;
    return dp[k][limit];
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    cout << divide(n,m);
}
