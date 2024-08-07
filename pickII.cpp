#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int n,m,k;
vector<vector<int>> g,pref;

inline int check(int r){
    for(int i=1;i<=n;i++){
        if(i-r+1 < 1)continue;
        for(int j=1;j<=m;j++){
            if(j-r+1 < 1)continue;
            int sum = pref[i][j] - pref[i-r][j] - pref[i][j-r] + pref[i-r][j-r];
            if(sum <= k)return true;
        }
    }
    return false;
}

inline void solve(){
    cin>>n>>m>>k;
    g.resize(n+1,vector<int> (m+1,0));
    pref.resize(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> g[i][j];
        }
    }
    pref = g;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            //cerr << pref[i][j] << ' ';
        }
        //cerr << '\n';
    }
    int l = 0,r = min(n,m)+1;
    while(l+1!=r){
        int m = (l+r)>>1;
        if(check(m))l = m;
        else r = m;
    }
    cout << l;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}