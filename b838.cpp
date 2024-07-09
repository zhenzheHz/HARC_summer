//https://zerojudge.tw/ShowProblem?problemid=b838
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    while(n--){
        string x;cin>>x;
        int iter = x.size(),cnt = 0;
        vector<int> stk;
        for(int i=0;i<iter;i++){
            if(x[i] == '(')stk.push_back(1);
            else{
                if(!stk.empty()){
                    if(stk.back() == 1){
                        stk.pop_back();
                        cnt += 1;
                    }
                }else stk.push_back(2);
            }
        }
        if(stk.empty())cout << cnt << '\n';
        else cout << 0 << '\n';
    }
}
