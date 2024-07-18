//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1955/problem/G
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    int max_value = 0,ans;
    for(int x=2;x<=n;x++){
        int sum = 0;
        for(int k=1;k*x<=n;k++){
            sum += k*x;
        }
        if(sum > max_value){
            max_value = sum;
            ans = x;
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
