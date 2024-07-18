//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1985/problem/E
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    int ans = 0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            int l = 0,r = z+1;
            while(l+1 != r){
                int m = (l+r)>>1;
                if(i*j*m > k)r = m;
                else l = m;
            }
            ans = max(ans,(i*j*l==k)*(x-i+1)*(y-j+1)*(z-l+1));
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
