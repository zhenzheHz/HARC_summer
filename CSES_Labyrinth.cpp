//Author : Zhenzhe
//Time : 2024/07/13(Sat)
//Problem : https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
using namespace std;
int32_t main(){
    FASTIO;
    int row,column;
    pair<int,int> A,B;
    vector<vector<int>> vis;
    cin >> row >> column;

    vis.resize(row,vector<int> (column,0));

    #define run(i,j) for(int i=0;i<row;i++)for(int j=0;j<column;j++)
    #define in(i,j) (i>=0&&i<row&&j>=0&&j<column)

    run(i,j){
        char c;cin>>c;
        if(c == 'A')A = {i,j};
        if(c == 'B')B = {i,j};
        if(c == '#')vis[i][j] = 1;
        else vis[i][j] = 0;
    }

    //bfs
    pair<int,int> dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    string dd = "DURL";

    vector<vector<int>> path(row,vector<int> (column,-1));
    queue<pair<int,int>> q;
    q.push(A);
    vis[A.X][A.Y] = 1;
    while(!q.empty()){
        auto cur = q.front();q.pop();
        for(int k=0;k<4;k++){
            auto nxt = dir[k];
            int x = cur.X + nxt.X;
            int y = cur.Y + nxt.Y;
            if(!in(x,y))continue;
            if(vis[x][y])continue;
            path[x][y] = k;
            q.push({x,y});
            vis[x][y] = 1;
        }
    }
    
    if(vis[B.X][B.Y] == 0){
        cout << "NO\n";
        return 0;
    }

    vector<int> PATH;
    while(B != A){
        int way = path[B.X][B.Y];
        PATH.push_back(way);
        int pre_x = B.X - dir[way].X;
        int pre_y = B.Y - dir[way].Y;
        B = {pre_x,pre_y};
    }
    reverse(PATH.begin(),PATH.end());
    cout << "YES\n" << PATH.size() << '\n';
    for(int &director : PATH){
        cout << dd[director];
    }
}
