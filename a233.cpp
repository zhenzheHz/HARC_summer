#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void merge_sort(vector<int> &arr,int l,int r){
    if(l == r)return;
    int m = (l+r)>>1;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    vector<int> left(arr.begin()+l,arr.begin()+m+1);
    vector<int> right(arr.begin()+m+1,arr.begin()+r+1);
    //merge
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    int lp = 0,rp = 0;
    for(int i=l;i<=r;i++){
        if(left[lp] <= right[rp]){
            arr[i] = left[lp];
            lp++;
        }else{
            arr[i] = right[rp];
            rp++;
        }
    }
    return;
}
int32_t main(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &i : a)cin >> i;
    merge_sort(a,0,n-1);
    for(int &i : a)cout << i << ' ';
}
