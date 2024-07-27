//Author : Zhenzhe
//Time : 2024/07/27(Sun)
//Problem : https://codeforces.com/contest/1992/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int sum,n;
    cin >> sum >> n;
    vector<int> a(n);
    for(int &i : a)cin>>i;
    sort(all(a));
    sum -= a[n-1];
    cout << sum*2-(n-1) << '\n';
}
int32_t main(){
    FASTIO;
    int test = 1;
    cin >> test;
    while(test--){
        solve();
    }
}
