//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1985/problem/H1
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            g[i][j] = (c=='#');
        }
    }
    vector<vector<int>> vis(n,vector<int> (m,0));
    vector<int> count(n*m+2,0);
    //=====dfs + dsu=====
    int id=1;
    function<void(int,int)> dfs = [&](int x,int y){
        if(g[x][y]==0 || vis[x][y])return;
        vis[x][y] = id;
        count[id] += 1;
        if(x-1>=0)dfs(x-1,y);
        if(x+1<n)dfs(x+1,y);
        if(y-1>=0)dfs(x,y-1);
        if(y+1<m)dfs(x,y+1);
    };
    //===================
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j] && !vis[i][j]){
                dfs(i,j);id++;
            }
        }
    }
    //brute force
    int ans = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        set<int> connect;
        for(int j=0;j<m;j++){
            if(vis[i][j])connect.insert(vis[i][j]);
            else sum += 1;
            if(i-1>=0)connect.insert(vis[i-1][j]);
            if(i+1<n)connect.insert(vis[i+1][j]);
        }
        for(int ID : connect)sum += count[ID];
        ans = max(ans,sum);
    }
    for(int j=0;j<m;j++){
        int sum = 0;
        set<int> connect;
        for(int i=0;i<n;i++){
            if(vis[i][j])connect.insert(vis[i][j]);
            else sum += 1;
            if(j-1>=0)connect.insert(vis[i][j-1]);
            if(j+1<m)connect.insert(vis[i][j+1]);
        }
        for(int ID : connect)sum += count[ID];
        ans = max(ans,sum);
    }
    cout << ans << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
