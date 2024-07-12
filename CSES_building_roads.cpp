//Author : Zhenzhe
//Time : 2024/07/13(Sat)
//Problem : https://cses.fi/problemset/task/1666
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec,sz) vec.resize(sz+1)
using namespace std;
vector<vector<int>> g;
vector<int> vis;

inline void dfs(int cur){
    if(vis[cur])return;
    vis[cur] = 1;
    for(int &nxt : g[cur]){
        dfs(nxt);
    }
}

int32_t main(){
    FASTIO;
    int n,m;
    cin >> n >> m;

    set(g,n+1);set(vis,n+1);

    while(m--){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> root;

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i);
        root.push_back(i);
    }

    if(root.size() == 1){
        cout << 0;
        return 0;
    }

    cout << root.size()-1 << '\n';
    for(int i=1;i<root.size();i++){
        cout << root[0] << ' ' << root[i];
        cout << '\n';
    }
}
