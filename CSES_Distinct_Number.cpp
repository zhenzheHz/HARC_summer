//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1621/
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int32_t main(){
    FASTIO;
    int n;cin>>n;
    set<int> s;
    while(n--){
        int k;cin>>k;
        s.insert(k);
    }
    cout << s.size();
}
