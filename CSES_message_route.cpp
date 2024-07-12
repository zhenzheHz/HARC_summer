//Author : Zhenzhe
//Time : 2024/07/13(Sat)
//Problem : https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec,sz) vec.resize(sz+1)
using namespace std;
int32_t main(){
    FASTIO;
    int n,m;cin>>n>>m;
    vector<int> g[n+1],dis(n+1,0),from(n+1,-1);
    while(m--){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //bfs
    queue<int> q;
    q.push(1);
    dis[1] = 1;
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int &nxt : g[cur]){
            if(dis[nxt])continue;
            q.push(nxt);
            dis[nxt] = dis[cur] + 1;
            from[nxt] = cur;
        }
    }
    if(dis[n] == 0){
        cout << "IMPOSSIBLE";return 0;
    }
    cout << dis[n] << '\n';
    vector<int> path;
    while(n != 1){
        path.push_back(n);
        n = from[n];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    for(int &node : path){
        cout << node << ' ';
    }
}
