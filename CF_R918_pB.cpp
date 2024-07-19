//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1915/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    string a,b,c;
    cin>>a>>b>>c;
    function<char(string)> check = [&](string s){
        map<char,int> mp;
        for(char c : s)mp[c]++;
        if(mp['A'] == 0)return 'A';
        else if(mp['B'] == 0)return 'B';
        else if(mp['C'] == 0)return 'C';
        else return 'X';
    };
    char x = check(a),y = check(b),z = check(c);
    if(x != 'X')cout << x;
    else if(y != 'X')cout << y;
    else cout << z;
    cout << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
