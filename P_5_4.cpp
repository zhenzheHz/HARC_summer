#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int recursion(vector<int> &a,int l,int r){
    if(r - l<1)return 0; 
    if(r-l==1){
        if(a[l] > a[r])return 1;
        else return 0;
    }
    int m = (l+r)>>1,cnt = 0;
    vector<int> l_arr(a.begin()+l,a.begin()+m+1);
    sort(l_arr.begin(),l_arr.end());
    for(int i=m+1;i<=r;i++){
        auto index = upper_bound(l_arr.begin(),l_arr.end(),a[i]) - l_arr.begin();
        if(index<0||index>=l_arr.size())continue;
        cnt += (l_arr.size() - index);
    }
    return recursion(a,l,m) + recursion(a,m+1,r) + cnt;
}
int32_t main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    cout << recursion(arr,0,n-1);
}
