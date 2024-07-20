//Author : Zhenzhe
//Time : 2024/07/20(Sat)
//Problem : https://codeforces.com/contest/1926/problem/G
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    vector<char> r(n+1);
    for(int i=1;i<=n;i++)cin>>r[i];
    int dp[n+1][3];
    //0 for C,1 for S,2 for P
    memset(dp,0,sizeof(dp));
    const int INF = 1e18;
    function<void(int,int)> dfs=[&](int cur,int from){
        for(int &nxt : g[cur]){
            if(nxt == from)continue;
            dfs(nxt,cur);
            if(r[cur] == 'C'){
                dp[cur][0] += min({dp[nxt][0],dp[nxt][1]+1,dp[nxt][2]+1});
                dp[cur][1] += min({dp[nxt][0],dp[nxt][1],dp[nxt][2]+1});
                dp[cur][2] += min({dp[nxt][0],dp[nxt][1]+1,dp[nxt][2]});
            }else if(r[cur] == 'S'){
                dp[cur][0] = dp[cur][2] = INF;
                dp[cur][1] += min({dp[nxt][0],dp[nxt][1],dp[nxt][2]+1});
            }else{
                dp[cur][0] = dp[cur][1] = INF;
                dp[cur][2] += min({dp[nxt][0],dp[nxt][1]+1,dp[nxt][2]});
            }
        }
        if(r[cur] == 'S')dp[cur][0] = dp[cur][2] = INF;
        else if(r[cur] == 'P')dp[cur][0] = dp[cur][1] = INF;
    };
    dfs(1,0);
    cout << min({dp[1][0],dp[1][1],dp[1][2]}) << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
