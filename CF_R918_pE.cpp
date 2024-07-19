//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1915/problem/E
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int &i : arr)cin>>i;
    int sum = 0;
    map<int,int>count;
    count[0] = 1;
    for(int i=0;i<n;i++){
        if(i&1)sum+=arr[i];
        else sum-=arr[i];
        count[sum]++;
        if(count[sum]>=2){
            cout << "Yes\n";return;
        }
    }
    cout << "No\n";
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
