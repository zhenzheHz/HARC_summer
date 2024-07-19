//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1926/problem/A
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    string s;cin>>s;
    int a=0,b=0;
    for(char &c : s){
        a += (c=='A');
        b += (c=='B');
    }
    if(a>b)cout << "A\n";
    else cout << "B\n";
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
