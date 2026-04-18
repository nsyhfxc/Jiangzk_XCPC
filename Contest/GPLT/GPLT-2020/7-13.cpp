#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
    }

    int a, b;
    cin >> a >> b;

    vector<int> vis(n + 1, 0);
    function<void(int)> mark = [&](int u) {
        vis[u] = 1;
        for (int v: g[u]) {
            if (!vis[v]) mark(v);
        }
    };
    mark(a);

    bool ok = true;
    for (int u = 1; u <= n; u++) {
        if (vis[u] && g[u].empty() && u != b) {
            ok = false;
        }
    }

    vector<i32> memo(n + 1, -1);
    function<i32(int)> dfs = [&](int u) -> i32 {
        if (memo[u] != -1) return memo[u];
        i32 res = 0;
        for (int v: g[u]) {
            if (v == b) res++;
            else res += dfs(v);
        }
        return memo[u] = res;
    };

    i32 cnt = dfs(a);
    cout << cnt << ' ' << (cnt > 0 && ok ? "Yes" : "No") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
