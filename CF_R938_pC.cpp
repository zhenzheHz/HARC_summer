//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1955/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n),pre(n),suf(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    pre[0] = arr[0];suf[n-1] = arr[n-1];
    for(int i=1;i<n;i++)pre[i] = pre[i-1]+arr[i];
    for(int i=n-2;i>=0;i--)suf[i]= suf[i+1] + arr[i];
    reverse(all(suf));
    int L = (k+1)/2,R = k/2;
    int a = lower_bound(all(pre),L) - pre.begin();
    int b = lower_bound(all(suf),R) - suf.begin();
    b = n-b-1;
    reverse(all(suf));
    if(a > b){
        cout << n << '\n';return;
    }
    int ans = 0;
    if(a < b){
        //check equal or greater
        if(pre[a] > L)ans += a;
        else ans += a+1;
        if(suf[b] > R)ans += n-b-1;
        else ans += n-b;
    }else{//(a == b)
        int total = pre[n-1];
        if(total > k)ans = n-1;
        else ans = n;
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
