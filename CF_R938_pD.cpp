//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1955/problem/D
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int &i : a)cin >> i;
    unordered_map<int,int> mp,b;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        b[x] += 1;
    }
    int L=0,R=0,ans=0,cur=0;
    for(R=0;R<m;R++){
        mp[a[R]]++;
        if(mp[a[R]] <= b[a[R]])cur++;
    }
    if(cur >= k)ans++;
    while(R < n){
        mp[a[L]] -= 1;
        if(mp[a[L]] < b[a[L]])cur--;
        L++;
        mp[a[R]] += 1;
        if(mp[a[R]] <= b[a[R]])cur++;
        R++;
        if(cur >= k)ans++;
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
