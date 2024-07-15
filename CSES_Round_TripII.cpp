//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1678
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb push_back
#define see(n) cerr<<n<<'\n'
using namespace std;
constexpr int INF = 1e18+5;
vector<int> path,vis;
vector<vector<int>> g;
int start_node;
inline bool dfs(int cur){
    vis[cur] = 1;
    for(int &nxt : g[cur]){
        path.push_back(nxt);
        if(vis[nxt] == 0){
            if(dfs(nxt))return true;
        }else if(vis[nxt] == 1){
            return true;
        }
        path.pop_back();
    }
    vis[cur] = 2;
    return false;
}
int32_t main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    set(g);set(vis);
    while(m--){
        int from,to;
        cin >> from >> to;
        g[from].pb(to);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        path.clear();
        path.pb(i);
        bool valid = dfs(i);
        if(!valid)continue;
        // see(i);//see(start_node);
        vector<int> ans;
        ans.pb(*path.rbegin());
        for(auto j=path.rbegin()+1;j<=path.rend();j++){
            ans.pb(*j);
            if(*j == *path.rbegin())break;
        }
        cout << ans.size() << '\n';
        reverse(all(ans));
        for(int &node : ans){
            cout << node << ' ';
        }
        return 0;
    }
    cout << "IMPOSSIBLE";
}
