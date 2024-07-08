//https://zerojudge.tw/ShowProblem?problemid=h084
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n,q;
vector<int> height,paste;
bool check(int h){
    int sum = 0,index = 0;
    for(int i=0;i<n;i++){
        if(index == q)return true;
        if(height[i] >= h)sum += 1;
        else sum = 0;
        // cerr << sum << '\n';
        if(sum >= paste[index]){
            index += 1;
            sum = 0;
        }
    }
    // cerr << index << '\n';
    return (index == q);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    height.resize(n);paste.resize(q);
    for(int &hs : height)cin >> hs;
    for(int &i : paste)cin >> i;
    int l=0,r=1e9+1;
    while(l+1 != r){
        int m = (l+r)>>1;
        // cerr << "m = " << m << '\n';
        if(check(m))l = m;
        else r = m;
    }
    cout << l;
}
