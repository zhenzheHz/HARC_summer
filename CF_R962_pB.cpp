// Author : Zhenzhe
// Time : 2024/07/26
// Problem : https://codeforces.com/contest/1996/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            grid[i][j] = (c=='1');
        }
    }
    vector<int> result;
    for(int i=0;i<n;i+=k){
        for(int j=0;j<n;j+=k){
            result.push_back(grid[i][j]);
            //trace(grid[i][j]);
        }
    }
    int x = 0;
    for(int i=0;i<n/k;i++){
        for(int j=0;j<n/k;j++){
            cout << result[x++];
        }
        cout << '\n';
    }
    //trace("-----");
}
int32_t main(){
    FASTIO;
    int test = 1;
    cin >> test;
    while(test--){
        solve();
    }
}
