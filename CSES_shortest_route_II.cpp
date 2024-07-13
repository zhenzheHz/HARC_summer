//Author : Zhenzhe
//Time : 2024/07/14(Sun)
//Problem : https://cses.fi/problemset/submit/1672/
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb emplace_back
using namespace std;
constexpr int INF = 1e18+5;
int32_t main(){
    FASTIO;
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> dis(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++)dis[i][i] = 0;
    while(m--){
        int a,b,x;
        cin >> a >> b >> x;
        dis[a][b] = dis[b][a] =min(dis[a][b],x);
    }
    //Floyd-warshall
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int from,to;
        cin >> from >> to;
        int ans = dis[from][to];
        if(ans == INF)cout << -1 << '\n';
        else cout << ans << '\n';
    }
}
