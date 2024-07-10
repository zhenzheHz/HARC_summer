#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Edge{
    int u,w;
    bool operator<(const Edge &cmp)const{
        return w>cmp.w;
    }
};
constexpr int INF = 1e18+5;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vector<vector<Edge>> g(n+1);
    vector<int> dis(n+1,INF);
    for(int i=1;i<n;i++){
        int a,b,x;
        cin >> a >> b >> x;
        g[i].push_back({i+1,a});
        g[i].push_back({x,b});
    }
    //dijkstra
    priority_queue<Edge> pq;
    pq.push({1,0});
    dis[1] = 0;
    while(!pq.empty()){
        auto edge = pq.top();pq.pop();
        int node = edge.u;
        int w = edge.w;
        for(auto &es : g[node]){
            if(es.w + dis[node] < dis[es.u]){
                dis[es.u]  = es.w + dis[node];
                pq.push({es.u,es.w + dis[node]});
            }
        }
    }
    cout << dis[n];
}
