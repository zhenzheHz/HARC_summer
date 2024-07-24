//Author : Zhenzhe
//Time : 2024/07/24(Wed)
//Problem : https://codeforces.com/contest/1907/problem/C
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<char,int> mp;
    int MAX = 0;
    for(char &c : s){
        mp[c]++;
        MAX = max(MAX,mp[c]);
    }
    int ans;
    if((MAX<<1) == n)ans = 0;
    else if((MAX<<1) < n){
        int rest = n-(MAX<<1);
        ans = rest&1;
    }else ans = (MAX<<1)-n;
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
