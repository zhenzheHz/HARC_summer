//Author : Zhenzhe
//Time : 2024/07/14(Sun)
//Problem : https://cses.fi/problemset/task/1673/
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
constexpr int INF = 1e18+5;
struct Edge{
    int from,to,w;
};
inline void dfs(vector<vector<int>> &graph,vector<int> &vis,int cur){
    if(vis[cur])return;
    vis[cur] = 1;
    for(int &nxt : graph[cur]){
        dfs(graph,vis,nxt);
    }
}
int32_t main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1),rg(n+1);
    vector<Edge> lst;
    while(m--){
        int a,b,x;
        cin >> a >> b >> x;
        g[a].pb(b);
        rg[b].pb(a);
        lst.push_back({a,b,-x});
    }
    vector<int> dis(n+1,INF);
    dis[1] = 0;
    //bellman-ford
    for(int i=1;i<n;i++){
        //relaxation
        for(auto &edge : lst){
            if(dis[edge.from] + edge.w < dis[edge.to]){
                dis[edge.to] = dis[edge.from] + edge.w;
            }
        }
    }
    //dfs
    vector<int> vis(n+1,0),rvis(n+1,0);
    dfs(g,vis,1);
    dfs(rg,rvis,n);
    //check cycle(n-th times relaxation)
    for(auto &edge : lst){
        if(dis[edge.from] + edge.w < dis[edge.to]){
            if(vis[edge.from]&&vis[edge.to]&&rvis[edge.from]&&rvis[edge.to]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << -dis[n];
}

