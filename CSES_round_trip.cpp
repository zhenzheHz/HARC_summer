//Author : Zhenzhe
//Time : 2024/07/13(Sat)
//Problem : https://cses.fi/problemset/task/1669
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb emplace_back
using namespace std;
int start_node;
vector<vector<int>> g;
vector<int> vis,path;
//dfs for check whether have cycle
inline bool dfs(int cur,int from){
    // cerr << "dfs : " << cur << '\n';
    if(vis[cur]){start_node = cur;return true;}
    vis[cur] = 1;
    path.pb(cur);
    for(int &nxt : g[cur]){
        if(nxt == from)continue;
        if(dfs(nxt,cur))return true;
    }
    path.pop_back();
    return false;
}
int32_t main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    set(g);set(vis);
    while(m--){
        int a,b;cin>>a>>b;
        g[a].pb(b);g[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        path.clear();
        bool have_cycle = dfs(i,-1);
        if(!have_cycle)continue;
        bool find = false;
        vector<int> ans;
        for(int &node : path){
            if(start_node == node)find = true;
            if(find)ans.pb(node);
        }
        ans.pb(start_node);
        // cerr << start_node;
        cout << ans.size() << '\n';
        for(int &node : ans){
            cout << node << ' ';
        }
        return 0;
    }
    cout << "IMPOSSIBLE";
}
