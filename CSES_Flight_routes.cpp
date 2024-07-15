//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1196
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb push_back
#define see(n) cerr<<n<<'\n'
using namespace std;
constexpr int INF = 1e18+5;
struct Edge{
    int to,w;
    bool operator<(const Edge &cmp)const{
        return w > cmp.w;
    }
};
int32_t main(){
    FASTIO;
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<Edge>> g(n+1);
    while(m--){
        int a,b,x;
        cin >> a >> b >> x;
        g[a].pb({b,x});
    }
    //dijkstra
    priority_queue<Edge> pq;
    pq.push({1,0});
    vector<int> vis(n+1,0);
    while(!pq.empty()&&vis[n]<k){
        auto cur = pq.top();pq.pop();
        if(cur.to == n)cout << cur.w << ' ';
        vis[cur.to] += 1;
        if(vis[cur.to] <= k){
            for(auto [node,distnace] : g[cur.to]){
                pq.push({node,distnace+cur.w});
            }
        }
    }
}
