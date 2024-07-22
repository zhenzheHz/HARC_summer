//Author : Zhenzhe
//Time : 2024/07/22(Mon)
//Problem : https://codeforces.com/contest/1927/problem/A
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int left = -1,right = -1;
    for(int i=0;i<n;i++){
        if(left == -1 && s[i] == 'B')left = i;
        if(left != -1 && s[i] == 'B')right = i;
    }
    cout << right-left+1 <<'\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
