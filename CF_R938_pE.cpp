//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1955/problem/E
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    int s[n+1];
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        s[i] = c-'0';
    }
    for(int k=n;k>0;k--){
        vector<int> inverse(n+100,0);
        int d = 0;//差分
        for(int i=1;i<=n-k+1;i++){
            d = (d+inverse[i])&1;
            int real_num = (s[i]+d)&1;
            if(real_num == 0){
                inverse[i+k] += 1;
                d += 1;
            }
        }
        //check
        bool ans = true;
        for(int i=n-k+2;i<=n;i++){
            d = (d+inverse[i])&1;
            int real_num = (s[i]+d)&1;
            if(real_num == 0){
                ans = false;
                break;
            }
        }
        if(ans){
            cout << k << '\n';return;
        }
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
