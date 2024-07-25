// Author : Zhenzhe
// Time : 2024/07/25
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int N = 2e5+10;
vector<int> pa(N),id(N),sz(N),sum(N);

int find(int x){
    if(x == pa[x])return x;
    return pa[x] = find(pa[x]);
}

void merge(int x,int y){
    x = find(id[x]),y = find(id[y]);
    if(x == y)return;
    pa[x] = y;
    sz[y] += sz[x];
    sum[y] += sum[x];
}
int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,q,op,a,b,x,y;
	while (cin >> n >> q) {
		for (int i = 1; i <= N; ++i)
			sz[i] = 1, pa[i] = id[i] = sum[i] = i;
		while (q--) {
			cin >> op;
			switch (op) {
			case 1:
				cin >> a >> b;
				merge(a,b);
				break;
			case 2:
				cin >> a >> b;
				x = find(id[a]), y = find(id[b]);
				if (x != y) {
					sum[x] -= a, --sz[x];
					id[a] = ++n;
					sum[id[a]] = a,sz[id[a]] = 1;
					merge(a,b);
				}
				break;
			default:
	            cin >> a;
				b = find(id[a]);
				cout << sz[b] << ' ' << sum[b] << '\n';
			}
		}
	}
}
