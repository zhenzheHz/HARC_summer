//Author : Zhenzhe
//Time : 2024/07/22(Mon)
//Problem : https://codeforces.com/contest/1927/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        for(int i=0;i<26;i++){
            if(mp[i] == x){
                char c = 'a'+i;
                cout << c;
                mp[i]++;
                break;
            }
        }
    }
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
