//Author : Zhenzhe
//Time : 2024/07/13(Sat)
//Problem : https://cses.fi/problemset/task/1194
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb emplace_back
using namespace std;
constexpr int INF = 1e18+5;
int row,column;
pair<int,int> nxt[4] = {{1,0},{-1,0},{0,1},{0,-1}};
#define in(i,j) (i>=0&&i<row&&j>=0&&j<column)
queue<pair<int,int>> q;
void bfs(vector<vector<int>> &dis){
    #define x first
    #define y second
    while(!q.empty()){
        auto cur = q.front();q.pop();
        for(auto &dir : nxt){
            int i = cur.x + dir.x;
            int j = cur.y + dir.y;
            if(!in(i,j)||dis[i][j] == INF||dis[i][j]!=-1)continue;
            q.push({i,j});
            dis[i][j] = dis[cur.x][cur.y] + 1;
        }
    }
}
//debug
void debug(string check,vector<vector<int>> &dis){
    cerr << check + " : \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(dis[i][j] == INF)cerr << 'X';
            else cerr << dis[i][j];
            cerr << ' ';
        }
        cerr << '\n';
    }
}
//

int32_t main(){
    FASTIO;
    cin >> row >> column;
    vector<vector<int>> player_dis,monster_dis;
    player_dis.resize(row,vector<int> (column,INF));
    monster_dis.resize(row,vector<int> (column,INF));

    pair<int,int> A;

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            char c;cin>>c;
            if(c == '#')continue;
            player_dis[i][j] = monster_dis[i][j] = -1;
            if(c == 'M'){q.push({i,j});monster_dis[i][j] = 0;}
            if(c == 'A')A = {i,j};
        }
    }
    // // debug("Monster",monster_dis);
    // // debug("Player",player_dis);
    
    //bfs to count distance
    bfs(monster_dis);
    q.push(A);
    player_dis[A.x][A.y] = 0;
    bfs(player_dis);
    // //check route
    debug("Monster",monster_dis);
    debug("Player",player_dis);

    vector<vector<int>> path;
    path.resize(row,vector<int> (column,INF));
    q.push(A);
    path[A.x][A.y] = 5;//impossible
    while(!q.empty()){
        auto cur = q.front();q.pop();
        for(int k=0;k<4;k++){
            auto dir = nxt[k];
            int i = cur.x + dir.x;
            int j = cur.y + dir.y;
            if(!in(i,j)||player_dis[i][j] == INF||path[i][j]!=INF)continue;
            if(monster_dis[i][j]==-1||player_dis[i][j] < monster_dis[i][j]){
                path[i][j] = k;
                q.push({i,j});
            }
        }
    }
    debug("Go",path);
    pair<int,int> B = {-1,-1};
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if((i!=0&&i!=row-1) && (j!=0&&j!=column-1))continue;
            // cerr << i << ' ' << j << '\n';
            if(path[i][j] == INF)continue;
            B = {i,j};
            break;
        }
    }
    // cerr << B.x << ' ' << B.y << '\n';
    if(B.x == -1){
        cout << "NO";return 0;
    }
    cout << "YES\n";
    cout << player_dis[B.x][B.y] << '\n';
    vector<int> ans;
    while(B != A){
        int pre = path[B.x][B.y];
        ans.pb(pre);
        B = {B.x-nxt[pre].x,B.y-nxt[pre].y};
    }
    //pair<int,int> nxt[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    string way = "DURL";//deal
    reverse(ans.begin(),ans.end());
    for(int &node : ans){
        cout << way[node];
    }
}
