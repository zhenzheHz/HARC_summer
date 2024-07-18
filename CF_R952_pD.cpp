//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1985/problem/D
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    int max_count = 0;
    pair<int,int> ans;
    vector<vector<int>> g(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=m;j++){
            char c;cin>>c;
            if(c == '#'){
                g[i][j] = 1;
                sum += 1;
            }
        }
        if(sum > max_count){
            max_count = sum;
            ans.first = i;
        }
    }
    int left = -1,right = -1;
    for(int j=1;j<=m;j++){
        if(left==-1 && g[ans.first][j] == 1)left = j;
        else if(left!=-1 && g[ans.first][j] == 0){right = j-1;break;}
    }
    if(right == -1)right = m;
    ans.second = (left+right)/2;
    cout << ans.first << ' ' << ans.second << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
