#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int N = 2e5+5,INF = 1e18+5;
int n;
vector<int> g[N];

inline int bfs(int st,int &long_dis){
    vector<int> dis(N,INF);
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while(q.size()){
        int cur = q.front();q.pop();
        for(int &nxt : g[cur]){
            if(dis[nxt] != INF)continue;
            q.push(nxt);
            dis[nxt] = dis[cur] + 1;
        }
    }
    int ans = -1,mx = 0;
    for(int i=1;i<=n;i++){
        if(dis[i] > mx){
            mx = dis[i];
            ans = i;
        }
    }
    long_dis = mx;
    return ans;
}

inline void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans = -1;
    int far = bfs(1,ans);
    //cerr << "FAR:" << far << '\n';
    bfs(far,ans);
    cout << (ans+1)/2 << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}