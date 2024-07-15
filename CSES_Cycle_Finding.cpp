//Author : Zhenzhe
//Time : 2024/07/15(Mon)
//Problem : https://cses.fi/problemset/task/1197
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define set(vec) vec.resize(n+1)
#define all(a) a.begin(),a.end()
#define pb push_back
#define see(n) cerr<<n<<'\n'
using namespace std;
constexpr int INF = 1e18+5;
struct Edge{
    int from,to,w;
};
int32_t main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    vector<Edge> lst;
    while(m--){
        int a,b,x;
        cin >> a >> b >> x;
        lst.pb({a,b,x});
    }
    //Bellman-Ford
    vector<int> dis(n+1,0x3f),parent(n+1,-1);
    dis[1] = 0;
    int relaxation;
    for(int i=1;i<=n;i++){
        relaxation = 0;
        for(auto [from,to,w] : lst){
            if(dis[from] + w < dis[to]){
                dis[to] = dis[from] + w;
                parent[to] = from;
                relaxation = to;
            }
        }
    }
    if(!relaxation){
        cout << "NO";return 0;
    }
    for(int i=0;i<n;i++)relaxation = parent[relaxation];
    cout << "YES\n";
    vector<int> cycle;
    for(int node=relaxation;;node=parent[node]){
        cycle.pb(node);
        if(node==relaxation&&cycle.size()>1)break;
    }
    reverse(all(cycle));
    for(int &node : cycle){
        cout << node << ' ';
    }
}
