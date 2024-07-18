//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1985/problem/F
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1e9+7;
int fpow(int a,int b){
    if(b == 0)return 1;
    if(b&1)return (a*fpow(a,b-1))%mod;
    int h = fpow(a,b>>1);
    return (h*h)%mod;
}
void solve(){
    int l,r,k;
    cin>>l>>r>>k;
    int ans;
    if(k > 9)ans = 0;
    else if(k == 1){
        ans = ((fpow(10LL,r)-fpow(10LL,l))%mod+mod)%mod;
    }else{
        int s = max(2LL,7LL-k);
        ans = ((fpow(s,r)-fpow(s,l))%mod+mod)%mod;
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
