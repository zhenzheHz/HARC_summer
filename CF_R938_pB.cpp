//Author : Zhenzhe
//Time : 2024/07/17(Wed)
//Problem : https://codeforces.com/contest/1955/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n,c,d;
    cin >> n >> c >> d;
    multiset<int> mat,check;
    for(int i=1;i<=n*n;i++){
        int k;cin>>k;
        mat.insert(k);
    }
    int a11 = *mat.begin();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check.insert(a11+i*c+j*d);
        }
    }
    for(int num : check){
        if(mat.find(num) == mat.end()){
            cout << "No\n";return;
        }else mat.erase(mat.find(num));
    }
    cout << "Yes\n";return;
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
