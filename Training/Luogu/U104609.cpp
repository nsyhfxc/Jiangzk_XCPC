#include<bits/stdc++.h>
using namespace std;
constexpr int N = 50010;
int n, siz[N], f[N], cnt = 1e9;
vector<int> e[N], g;

void dfs(const int &u, const int &fa) {
    siz[u] = 1;
    for (auto v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        f[u] = max(f[u], siz[v]);
        siz[u] += siz[v];
    }
    f[u] = max(f[u], n - siz[u]);
    cnt = min(cnt, f[u]);
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].emplace_back(b);
        e[b].emplace_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) if (f[i] == cnt) g.emplace_back(i);
    for (const auto &v: g) cout << v << " ";
    return 0;
}
