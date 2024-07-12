//Author : Zhenzhe
//Time : 2024/07/12(Fri)
//Problem : https://cses.fi/problemset/task/1137
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int N = 2e5+5;
int n,q;
vector<int> g[N],in(N),out(N),val(N);
//---binary indexed tree
vector<int> bit(N,0);//-> flatten
#define lbt(i) (i&-i)
inline void update(int p,int i){
    while(p<=n){
        bit[p] += i;
        p += lbt(p);
    }
}
inline int query(int p){
    int sum = 0;
    while(p>0){
        sum += bit[p];
        p -= lbt(p);
    }
    return sum;
}
//----
void dfs(int cur,int from){
    static int timer = 0;
    in[cur] = ++timer;
    for(int &nxt : g[cur]){
        if(nxt == from)continue;
        dfs(nxt,cur);
    }
    out[cur] = timer;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> val[i];
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);
    for(int i=1;i<=n;i++){
        update(in[i],val[i]);
    }

    // for(int i=1;i<=n;i++){
    //     cerr << in[i] << ' ' << out[i] << '\n';
    // }

    while(q--){
        int operation,a,b;
        cin >> operation;
        if(operation == 1){
            cin >> a >> b;
            update(in[a],b - val[a]);
            val[a] = b;
        }else{
            cin >> a;
            cout << query(out[a]) - query(in[a] - 1) << '\n';
        }
    }
}
