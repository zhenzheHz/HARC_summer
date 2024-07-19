//Author : Zhenzhe
//Time : 2024/07/19(Fri)
//Problem : https://codeforces.com/contest/1926/problem/B
#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    vector<string> mat(n);
    for(string &row : mat)cin>>row;
    unordered_set<int> s;
    for(string &row : mat){
        int sum=0;
        for(char &col : row){
            sum += (col=='1');
        }
        s.insert(sum);
    }
    if(s.size() == 1||s.size()==2)cout << "SQUARE\n";
    else cout << "TRIANGLE\n";
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
