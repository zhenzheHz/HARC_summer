#include <bits/stdc++.h>
#define int int64_t
using namespace std;

inline void solve(){
    int n,m;cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        arr[i] += arr[i-1];
    }
    while(m--){
        int k;cin>>k;
        auto f = upper_bound(arr.begin(),arr.end(),k);
        if(f == arr.begin()){
            cout << 0 << '\n';
        }else{
            f = f-1;
            cout << f-arr.begin()+1 << '\n';
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}
