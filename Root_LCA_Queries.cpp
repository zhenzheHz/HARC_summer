i#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << "\n"), ...);}
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define trace_vector(s,v) cerr<<s<<'\n';for(auto i : v)cerr<<i<<' ';cerr<<'\n'
static constexpr int N = 1e5+5;
struct query{
    int a,b,id;  
};
int n;//global
vector<int> g[N],vis(N,0),parent(N,0),lca(N),sz(N,1),id[N],ans(N);
vector<query> Q[N];
inline int find(int x){
    if(x == parent[x])return x;
    return parent[x] = find(parent[x]);
}
inline void dfs(int cur,int from){
    sz[cur] = 1;
    unordered_set<int> son;
    for(int &nxt : g[cur]){
        if(nxt == from)continue;
        dfs(nxt,cur);
        son.insert(nxt);
        sz[cur] += sz[nxt];
    }
    for(auto &[a,b,i] : Q[cur]){
        int pa = find(a),pb = find(b);
        if(son.find(pa) == son.end())pa = 0;
        if(son.find(pb) == son.end())pb = 0;
        if(pa == pb){
            //a and b are not in subtree
            ans[i] = 0;
            continue; 
        }
        sz[0] = n - sz[cur];
        ans[i] = n - sz[pa] - sz[pb];
    }
    for(int &nxt : g[cur]){
        if(nxt == from)continue;
        parent[nxt] = cur;
    }
}
int32_t main(){
    FASTIO;
    int q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)parent[i] = i;
    for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Q[c].push_back({a,b,i});
    }
    dfs(1,1);
    for(int i=0;i<q;i++){
        cout << ans[i] << '\n';
    }
}
