//https://zerojudge.tw/ShowProblem?problemid=f679
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &i : a)cin >> i;
    while(q--){
        int x;cin>>x;
        int index = lower_bound(a.begin(),a.end(),x)-a.begin();
        if(index<0||index>=n||a[index]!=x){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
}
