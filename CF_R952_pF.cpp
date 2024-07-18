//Author : Zhenzhe
//Time : 2024/07/18(Thu)
//Problem : https://codeforces.com/contest/1985/problem/F
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int h,n;
    cin>>h>>n;
    int max_cd = 0;
    vector<pair<int,int>> skills(n);
    for(int i=0;i<n;i++)cin>>skills[i].first;
    for(int i=0;i<n;i++){
        cin>>skills[i].second;
        max_cd = max(max_cd,skills[i].second);
    }
    //check function
    auto defeat = [&](int turns){
        int total_damage = 0;
        for(auto [damage,cd] : skills){
            total_damage += ((turns-1)/cd + 1)*damage;
            if(total_damage>=h)return true;
        }
        return false;
    };
    //binary search
    int l=0,r=max_cd*(h+10);
    while(l+1 != r){
        int m = (l+r)>>1;
        if(defeat(m))r = m;
        else l = m;
    }
    cout << r << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
