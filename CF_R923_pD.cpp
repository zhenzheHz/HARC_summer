//Author : Zhenzhe
//Time : 2024/07/22(Mon)
//Problem : https://codeforces.com/contest/1927/problem/D
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> distinct(n+1,0),a(n+1,0);
    for(int i=1;i<=n;i++){
        distinct[i] = i;
        cin >> a[i];
        if(a[i] == a[i-1]){
            distinct[i] = distinct[i-1];
        }
    }
    int queries;cin>>queries;
    while(queries--){
        int l,r;cin>>l>>r;
        if(distinct[r] <= l){
            cout << "-1 -1\n";
        }else cout << distinct[r]-1 << '\n';
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
