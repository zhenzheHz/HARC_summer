//Author : Zhenzhe
//Time : 2024/07/13(Sat)
//Problem : https://cses.fi/problemset/task/1192
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int row,column;
vector<vector<int>> vis;

#define in(i,j) (i>=0&&i<row&&j>=0&&j<column)

inline void dfs(int x,int y){
    if(vis[x][y])return;
    vis[x][y] = 1;
    if(in(x-1,y))dfs(x-1,y);
    if(in(x+1,y))dfs(x+1,y);
    if(in(x,y-1))dfs(x,y-1);
    if(in(x,y+1))dfs(x,y+1);
}

int32_t main(){
    FASTIO;
    cin >> row >> column;
    vis.resize(row,vector<int> (column,0));

    #define run(i,j) for(int i=0;i<row;i++)for(int j=0;j<column;j++)
    
    run(i,j){
        char c;cin>>c;
        if(c == '#')vis[i][j] = 1;
        else vis[i][j] = 0;
    }

    int count_of_room = 0;
    run(i,j){
        if(vis[i][j])continue;
        count_of_room += 1;
        dfs(i,j);
    }
    
    cout << count_of_room;
}
