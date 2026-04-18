#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct DSU {
    vector<i32> fa;
    vector<i32> sz;

    explicit DSU(i32 n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        sz.assign(n + 1, 1);
    }

    int find(const int &x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    void unite(const int &x, const int &y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            fa[rootx] = rooty;
            sz[rooty] += sz[x];
        }
    }

    bool same(const int &x, const int &y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<i32> par(n + 1), dep(n + 1);
    vector<vector<int> > g(n + 1);
    int rt = 0;

    for (int i = 1; i <= n; i++) {
        cin >> par[i];
        if (par[i] == -1) {
            rt = i;
        } else {
            g[par[i]].emplace_back(i);
        }
    }

    vector<int> stk;
    stk.emplace_back(rt);
    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        for (int v: g[u]) {
            dep[v] = dep[u] + 1;
            stk.emplace_back(v);
        }
    }

    DSU dsu(n);
    i32 len = 0;
    i32 mx = 0;

    while (m--) {
        int x;
        cin >> x;

        mx = max(mx, dep[x]);

        int u = x;
        while (!dsu.same(u, rt)) {
            ++len;
            dsu.unite(u, rt);
            u = par[u];
        }

        cout << len * 2 - mx << endl;
    }
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
