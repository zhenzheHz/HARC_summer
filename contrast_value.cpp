#include <bits/stdc++.h>
#define int int64_t
using namespace std;
inline void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    if(n == 1)return cout<<1<<'\n',void();
    if(n == 2)return cout<<((arr[0]==arr[1])? 1:2)<<'\n',void();
    vector<bool> del(n,false);
    array<int,3> tmp = {arr[0],arr[1],arr[2]};
    for(int i=1;i<n-1;i++){
        tmp[2] = arr[i+1];
        //cerr << tmp[0] << ' ' << tmp[1] << ' ' << tmp[2] << '\n';
        if(tmp[0]<=tmp[1]&&tmp[1]<=tmp[2]){
            tmp[1] = tmp[2];
            del[i] = true;
        }else if(tmp[0]>=tmp[1]&&tmp[1]>=tmp[2]){
            tmp[1] = tmp[2];
            del[i] = true;
        }else{
            tmp[0] = tmp[1];
            tmp[1] = tmp[2];
        }
    }
    if(tmp[2] == tmp[0])del[n-1] = true;
    int ans = 0;
    //cerr << "DELETE : \n";
    for(int i=0;i<n;i++){
        //cerr << del[i] << ' '; 
        ans += (!del[i]);
    }
    //cout << "ANS : ";
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
