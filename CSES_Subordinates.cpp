//Author : Zhenzhe
//Time : 2024/07/16(Tue)
//Problem : https://cses.fi/problemset/task/1674/
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb push_back
#define see(n) cerr<<n<<'\n'
using namespace std;
constexpr int INF = 1e18+5;
vector<vector<int>> g;
vector<int> in,out;
void dfs(int cur,int from){
    static int timer = 0;
    in[cur] = ++timer;
    for(int &nxt : g[cur]){
        if(from == nxt)continue;
        dfs(nxt,cur);
    }
    out[cur] = timer;
}
int32_t main(){
    FASTIO;
    int n;cin>>n;
    set(g);set(in);set(out);
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        g[p].pb(i);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        // see(in[i]);see(out[i]);
        cout << out[i]-in[i] << ' ';
    }
}
