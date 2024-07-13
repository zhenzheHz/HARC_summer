//Author : Zhenzhe
//Time : 2024/07/14(Sun)
//Problem : https://cses.fi/problemset/task/1671
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb emplace_back
using namespace std;
constexpr int INF = 1e18+5;
struct Edge{
    int to,w;
    bool operator<(const Edge& cmp)const{
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
        g[a].push_back({b,x});
        g[b].push_back({a,x});
    }
    //dijkstra
    vector<int> dis(n+1,INF);
    dis[1] = 0;
    priority_queue<Edge> pq;
    pq.push({1,0});
    vector<bool> mark(n+1,false);
    while(!pq.empty()){
        auto cur = pq.top();pq.pop();
        for(auto &edge : g[cur.to]){
            if(dis[cur.to] + edge.w < dis[edge.to]){
                dis[edge.to] = dis[cur.to] + edge.w;
                pq.push({edge.to,dis[cur.to] + edge.w});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dis[i] << ' ';
    }
}
