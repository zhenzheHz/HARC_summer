//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1985/problem/C
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> arr(n),pre(n);
    for(int &i : arr)cin >> i;
    int max_value = 0,ans = 0,sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        max_value = max(max_value,arr[i]);
        if(sum == max_value*2)ans+=1;
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
