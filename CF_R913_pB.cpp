//Author : Zhenzhe
//Time : 2024/07/24(Wed)
//Problem : https://codeforces.com/contest/1907/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
void solve(){
    string s;cin>>s;
    vector<bool> display(s.size(),true);
    vector<int> lower,upper;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'b'){
            display[i] = false;
            if(lower.empty())continue;
            display[lower.back()] = false;
            lower.pop_back();
        }else if(s[i] == 'B'){
            display[i] = false;
            if(upper.empty())continue;
            display[upper.back()] = false;
            upper.pop_back();
        }else{
            if((int32_t) s[i] >= 97)lower.push_back(i);
            else upper.push_back(i);
        }
    }
    for(int i=0;i<s.size();i++){
        if(display[i])cout<<s[i];
    }
    cout << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
