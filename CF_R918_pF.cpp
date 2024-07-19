//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1915/problem/F
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(all(a));
    vector<int> x(n);
    for(int i=0;i<n;i++){
        x[i] = a[i].second;
    }
    function<int(int,int)> inversion=[&](int l,int r)->int{
        if(r-l<=0)return 0;
        int m = (l+r)>>1;
        vector<int> left(x.begin()+l,x.begin()+m+1);
        sort(all(left));
        int count = 0;
        for(int i=m+1;i<=r;i++){
            int index = upper_bound(all(left),x[i])-left.begin();
            if(index<0||index>=left.size())continue;
            count += (left.size()-index);
        }
        return count+inversion(l,m)+inversion(m+1,r);
    };
    cout << inversion(0,n-1) << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
