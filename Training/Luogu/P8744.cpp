#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100005;
int n, f[N], son[N];
int head[N], idx;

struct Edge {
    int v, ne;
} edge[N << 1];

void add(int u, int v) {
    edge[++idx] = {v, head[u]};
    head[u] = idx;
}

void dfs(int u) {
    for (int i = head[u]; i; i = edge[i].ne) {
        int v = edge[i].v;
        dfs(v);
        f[u] = max(f[u], f[v]);
    }
    f[u] += son[u];
}

signed main() {
    cin >> n;
    for (int i = 2, u; i <= n; ++i)
        cin >> u, add(u, i), ++son[u];
    dfs(1);
    cout << f[1];
}
