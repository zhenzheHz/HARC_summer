//https://zerojudge.tw/ShowProblem?problemid=f815
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n,m;
bool check(vector<int> &s,int level){
    int cost = 0;
    for(int &i : s){
        if(i < level){
            cost += (level-i)*(level-i);
        }
    }
    // cerr << level << ' ' << cost << '\n';
    return (cost<=m);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> a(n);
    for(int &i : a)cin >> i;
    int l = -1,r = 1e7+1;
    while(l+1 != r){
        int m = (l+r)>>1;
        if(check(a,m))l = m;
        else r = m;
    }
    cout << l;
}
