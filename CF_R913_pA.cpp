//Author : Zhenzhe
//Time : 2024/07/24(Wed)
//Problem : https://codeforces.com/contest/1907/problem/A
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    string s;cin>>s;
    char col = s[0];
    int row = s[1]-'0';
    for(int i=1;i<=8;i++){
        if(i == row)continue;
        cout << col << i << '\n';
    }
    for(char x = 'a';x!='i';x += 1){
        if(x == col)continue;
        cout << x << row << '\n';
    }
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
