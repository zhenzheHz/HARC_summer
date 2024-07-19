//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1915/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    int sum = 0;
    while(n--){
        int k;cin>>k;
        sum += k;
    }
    int l = 0,r = sqrt(sum)+2;
    while(l+1!=r){
        int m =(l+r)>>1;
        if(m*m <= sum)l = m;
        else r = m;
    }
    if(l*l == sum)cout << "Yes\n";
    else cout << "No\n";
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
