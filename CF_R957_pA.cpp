//Author : Zhenzhe
//Time : 2024/07/27(Sun)
//Problem : https://codeforces.com/contest/1992/problem/A
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans = 0;
    for(int i=0;i<=5;i++){
        for(int j=0;j<=5-i;j++){
            for(int k=0;k<=5-i-j;k++){
                int x = a+i,y = b+j,z = c+k;
                ans = max(ans,x*y*z);
            }
        }
    }
    cout << ans << '\n';
}
int32_t main(){
    FASTIO;
    int test = 1;
    cin >> test;
    while(test--){
        solve();
    }
}
