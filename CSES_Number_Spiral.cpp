//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1071
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T>
void see(T&&... args) { ((cout << args << "\n"), ...);}
template<typename... T>
void saw(T&&... args) { ((cerr << args << "\n"), ...);}
int32_t main(){
    int queries;
    cin >> queries;
    while(queries--){
        int row,column;
        cin >> row >> column;
        if(row > column){
            if(row&1)see((row-1)*(row-1)+column);
            else see(row*row-column+1);
        }else{
            if(column&1)see(column*column-row+1);
            else see((column-1)*(column-1)+row);
        }
    }
}
