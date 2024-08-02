#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

inline void solve(int n){
	string s;cin>>s;
	vector<queue<int>> ap(26);
	for(int i=0;i<n;i++){
		ap[s[i]-'a'].push(i);
	}
	for(int i=0;i<26;i++){
		if(ap[i].empty()){
			cout << "not found\n";
			return;
		}
	}
	int l=0,r = 0,segment;
	pair<int,int> ans;
	for(int i=0;i<26;i++){
		r = max(r,ap[i].front());
	}
	ans = {l,r};
	segment = r-l+1;
	bool check = false;
	while(r < n){
		l += 1;
		for(int i=0;i<26;i++){
			while(ap[i].size() && ap[i].front() < l){
				ap[i].pop();
			}
			if(ap[i].empty()){
				check = true;
				break;
			}
			r = max(r,ap[i].front());
		}
		if(check)break;
		if(r-l+1 < segment){
			segment = r-l+1;
			ans = {l,r};
		}
	}
	for(int i=ans.first;i<=ans.second;i++){
		cout << s[i];
	}
	cout << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		if(n)solve(n);
		else break;
	}
}
