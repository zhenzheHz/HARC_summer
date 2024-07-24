//Author : Zhenzhe
//Time : 2024/07/24(Wed)
//Problem : https://codeforces.com/contest/1907/problem/D
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    int n;cin>>n;
    vector<pair<int,int>> seg(n);
    for(auto &i : seg){
        cin >> i.first >> i.second;
    }
    int l = -1,r = 1e9+1;
    function<bool(int)>check=[&](int k)->bool{
        int L = 0,R = 0;
        for(auto &[l,r] : seg){
            L = max(l,L-k);
            R = min(r,R+k);
            if(R<L)return false;
            //if(debug)trace(L,R);
        }
        return true;
    };
    while(l+1!=r){
        int m = (l+r)>>1;
        if(check(m))r = m;
        else l = m;
    }
    cout << r << '\n';
    //trace(r,"-----");
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
