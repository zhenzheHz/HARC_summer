//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1926/problem/E
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    /*
    1,3,5,7,9.... -> (n+1)/2 = s1
    2,6,10,..... -> (n - s1)+1 / 2 = s2 
    3,9,15,...... -> (n-s1-s2)+1 /2 = s3 //none
    so on...
    */
    int n,k;
    cin>>n>>k;
    int tmp = n,times = 1;
    while(k > (tmp+1)>>1){
        // cerr << ((tmp+1)>>1) << '\n';
        k -= (tmp+1)>>1;
        tmp >>= 1;
        times <<= 1;
    }
    int ans = times+(k-1)*2*times;
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
