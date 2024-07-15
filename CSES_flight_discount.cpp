//Author : Zhenzhe
//Time : 2024/07/15(Mon)
//Problem : https://cses.fi/problemset/task/1195
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
constexpr int INF = 1e18+5;
struct Edge{
    int to,w;
    bool used;
    bool operator<(const Edge &cmp)const{
        return w > cmp.w;
    }
};
int32_t main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    vector<vector<Edge>> g(n+1);
    while(m--){
        int a,b,x;
        cin >> a >> b >> x;
        g[a].pb({b,x,false});
    }
    //dijkstra;
    vector<vector<int>> dis(n+1,vector<int> (2,INF));
    dis[1][0] = 0;
    priority_queue<Edge> pq;
    pq.push({1,0,false});
    while(!pq.empty()){
        auto cur = pq.top();pq.pop();
        if(cur.w > dis[cur.to][cur.used])continue;
        for(auto &edge : g[cur.to]){
            if(dis[cur.to][cur.used] + edge.w < dis[edge.to][cur.used]){
                dis[edge.to][cur.used] = dis[cur.to][cur.used] + edge.w;
                pq.push({edge.to,dis[edge.to][cur.used],cur.used});
            }
            if(!cur.used){
                if(cur.w + edge.w/2 < dis[edge.to][true]){
                    dis[edge.to][true] = cur.w + edge.w/2;
                    pq.push({edge.to,dis[edge.to][true],true});
                }
            }
        }
    }
    cout << dis[n][true];
}
