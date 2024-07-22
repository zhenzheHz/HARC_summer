//Author : Zhenzhe
//Time : 2024/07/22(Mon)
//Problem : https://codeforces.com/contest/1927/problem/C
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    unordered_map<int,int> a,b;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a[x]++;
    }
    for(int i=0;i<m;i++){
        int x;cin>>x;
        b[x]++;
    }
    int c1=0,c2=0;
    bool have = true;
    for(int i=1;i<=k;i++){
        if(a[i]==0&&b[i]==0){
            have = false;
            break;
        }
        if(a[i]&&b[i]==0)c1++;
        if(a[i]==0&&b[i])c2++;
    }
    if(have && (c1>k/2||c2>k/2))have = false;
    if(have)cout << "Yes\n";
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
