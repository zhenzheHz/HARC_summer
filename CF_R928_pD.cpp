//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1926/problem/D
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int &i : a){
        cin >> i;
        mp[i]++;
    }
    int ans = n;
    for(int &i : a){
        if(mp[i] == 0)continue;
        //INT_MAX = 2^31-1
        //for binary is 11111...11(x31)
        int inverse = i^INT_MAX;//get the reverse
        if(mp[inverse]){
            ans--;
            mp[inverse]--;
            mp[i]--;
        }
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
