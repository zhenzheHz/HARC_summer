#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr(n),ans(n,-1);
	for(int i=0;i<n;i++){
	    cin >> arr[i];
		ans[i] = i;
	}
	stack<int> stk;
	for(int i=n-1;i>=0;i--){
	    while(stk.size() && arr[i] < arr[stk.top()]){
	        ans[stk.top()] = i+1;
	        stk.pop();
	    }
	    stk.push(i);
	}
	while(stk.size()){
	    ans[stk.top()] = 0;
	    stk.pop();
	}
	for(int i=0;i<n;i++){
	    cout << ans[i] << ' ';
	}
}
