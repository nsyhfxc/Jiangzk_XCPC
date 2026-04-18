#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

struct DSU {
    vector<i32> fa;
    vector<i32> sz;
    DSU(i32 n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        sz.assign(n + 1, 1);
    }
    i32 find(i32 x) {
        if (fa[x] == x) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }
    void unite(i32 x, i32 y) {
        i32 rootx = find(x);
        i32 rooty = find(y);
        if (rootx != rooty) {
            fa[rootx] = rooty;
            sz[rooty] += sz[rootx];
        }
    }
    bool same(i32 x, i32 y) {
        return find(x) == find(y);
    }
};

void solve() {
    i32 n, m;
    cin >> n >> m;
    vector<pair<i32, i32> > edges(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    DSU dsu(n);
    i32 mx = 1;
    vector<i32> res;
    for (int i = m - 1; i >= 0; --i) {
        res.push_back(mx);
        i32 u = edges[p[i]].first;
        i32 v = edges[p[i]].second;
        i32 rootu = dsu.find(u);
        i32 rootv = dsu.find(v);
        if (rootu != rootv) {
            dsu.unite(u, v);
            mx = max(mx, dsu.sz[dsu.find(v)]);
        }
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < m; ++i) {
        cout << res[i] << (i == m - 1 ? "" : " ");
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
