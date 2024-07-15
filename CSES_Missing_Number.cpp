//Author : Zhenzhe
//Time : 2024/07/16(Tue)https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T>
void see(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void saw(T&&... args) { ((cerr << args << " "), ...);}
int32_t main(){
    int n;cin>>n;
    bitset<200005> mark;
    mark.reset();
    for(int i=1;i<=n;i++){
        int num;cin>>num;
        mark[num] = 1;
    }
    for(int i=1;i<=n;i++){
        //saw(mark[i])
        if(mark[i] == 0){
            see(i);
            break;
        }
    }
}
