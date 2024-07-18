//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1955/problem/G
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
vector<int> find_factor(int n){
    vector<int> div;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            div.push_back(i);
            if(i != n/i)div.push_back(n/i);
        }
    }
    return div;
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int> (m,0));
    for(auto &row : g){
        for(auto &i : row)cin >> i;
    }
    auto bfs = [&](int x){
        bitset<100005> vis;
        queue<int> q;
        vis.set(0);
        q.push(0);
        while(!q.empty()){
            int idx = q.front();q.pop();
            int i = idx/m,j = idx%m;
            if(i == n-1 && j == m-1)return true;
            if (j+1<m && !vis.test(idx+1) && g[i][j+1]%x == 0) {
                vis.set(idx + 1);
                q.push(idx + 1);
            }
            if (i+1<n && !vis.test(idx+m) && g[i+1][j]%x == 0) {
                vis.set(idx + m);
                q.push(idx + m);
            }
        }
        return false;
    };
    int tar = __gcd(g[0][0],g[n-1][m-1]);
    vector<int> div = find_factor(tar);
    sort(all(div));
    set<int> ban;
    auto check = [&](int x){
        for(auto y : ban){
            if(x%y == 0)return false;
        }
        return true;
    };
    int ans = 1;
    for (auto x: div) {
        if (check(x)) {
            if (bfs(x))ans = x;
            else ban.insert(x);
        }
    }
    cout << ans << "\n";
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
