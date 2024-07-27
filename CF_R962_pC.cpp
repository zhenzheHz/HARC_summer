// Author : Zhenzhe
// Time : 2024/07/26
// Problem : https://codeforces.com/contest/1996/problem/C
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int n,q;
    cin >> n >> q;
    string a,b;
    cin >> a >> b;
    vector<vector<int>> ca,cb(n+1,vector<int> (26,0));
    ca = cb;
    for(int i=1;i<=n;i++){
        ca[i] = ca[i-1];
        cb[i] = cb[i-1];
        ca[i][a[i-1]-'a'] += 1;
        cb[i][b[i-1]-'a'] += 1;
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        int ans = 0;
        for(int i=0;i<26;i++){
            int sa = ca[r][i]-ca[l-1][i];
            int sb = cb[r][i]-cb[l-1][i];
            ans += max(abs(sa-sb),(int64_t) 0);
        }
        cout << ans/2 << '\n';
    }
}
int32_t main(){
    FASTIO;
    int test = 1;
    cin >> test;
    while(test--){
        solve();
    }
}
