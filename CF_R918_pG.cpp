//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1915/problem/G
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
struct Edge{
    int node,w,slow;
    bool operator<(const Edge& cmp)const{
        return w > cmp.w;
    }
};
void solve(){
    const int INF = 1e18;
    int n,m;
    cin>>n>>m;
    vector<vector<Edge>> g(n+1);
    while(m--){
        int a,b,x;
        cin>>a>>b>>x;
        g[a].push_back({b,x,-1});
        g[b].push_back({a,x,-1});
    }
    vector<int> s(n+1);
    for(int i=1;i<=n;i++)cin>>s[i];
    vector<vector<int>> dis(n+1,vector<int>(1001,INF));
    dis[1][s[1]] = 0;
    priority_queue<Edge> pq;
    pq.push({1,0,s[1]});//node,distance,s[node]
    //dijkstra
    while(!pq.empty()){
        auto cur = pq.top();pq.pop();
        if(cur.w > dis[cur.node][cur.slow])continue;
        for(auto &[to,w,tmp] : g[cur.node]){
            int bike = min(s[to],cur.slow);
            int new_dis = cur.w + w*cur.slow;
            if(new_dis < dis[to][bike]){
                dis[to][bike] = new_dis;
                pq.push({to,new_dis,bike});
            }
        }
    }
    cout << *min_element(all(dis[n])) << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
