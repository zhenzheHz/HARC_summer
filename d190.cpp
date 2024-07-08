https://zerojudge.tw/ShowProblem?problemid=d190
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    int n;
    while(cin >> n){
        ios_base::sync_with_stdio(false);cin.tie(0);
        vector<int> s(n);
        for(int &i : s)cin >> i;
        sort(s.begin(),s.end());
        for(int &i : s)cout << i << ' ';
        cout << '\n';
    }
}
