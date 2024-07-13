//Author : Zhenzhe
//Time : 2024/07/13(Sat)
//Problem : https://cses.fi/problemset/task/1668
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec,sz) vec.resize(sz+1)
#define all(a) a.begin(),a.end()
#define pb emplace_back
using namespace std;
vector<vector<int>> g;
vector<int> color;
inline bool dfs(int node,int will){
    if(color[node])return (color[node] == will);
    color[node] = will;
    for(int &nxt : g[node]){
        if(!dfs(nxt,3-will)){
            return false;
        }
    }
    return true;
}
int32_t main(){
    FASTIO;
    int n,m;cin>>n>>m;
    set(g,n);set(color,n);
    while(m--){
        int a,b;cin>>a>>b;
        g[a].pb(b);g[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(color[i])continue;
        if(dfs(i,1))continue;
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout << color[i] << ' ';
    }
}
