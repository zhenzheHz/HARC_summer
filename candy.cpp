#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int mod = 1e9+7;
int fp(int a,int b){
    if(b == 0)return 1;
    if(b&1)return (a*fp(a,b-1))%mod;
    int h = fp(a,b>>1);
    return (h*h)%mod;
}
int32_t main(){
    int n,c;
    cin >> n >> c;
    vector<int> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    const int N = 405;
    vector<vector<int>> sum(N,vector<int> (N,0)),dp(N,vector<int> (N,0));
    //sum[i][x] = \sigma_k=a[i]^b[i] k^x
    for(int i=1;i<=n;i++){
        for(int j=0;j<=c;j++){
            for(int k=a[i];k<=b[i];k++){
                sum[i][j] += (fp(k,j))%mod;
                sum[i][j] %= mod;
            }
        }
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=c;j++){
            for(int k=0;k<=j;k++){
                dp[i][j] += dp[i-1][j-k] * sum[i][k] %mod;
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][c]%mod;
}
