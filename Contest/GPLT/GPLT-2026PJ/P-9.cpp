#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct DSU {
    vector<int> fa, sz;
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        fa.resize(n);
        sz.assign(n, 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while (fa[x] != x) {
            fa[x] = fa[fa[x]];
            x = fa[x];
        }
        return x;
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > sen(n);
    vector<vector<int> > occ(m + 1);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> v(k);
        for (int j = 0; j < k; j++) cin >> v[j];

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end()); // 同一句去重
        sen[i] = std::move(v);

        for (auto &w: sen[i]) occ[w].emplace_back(i);
    }

    DSU dsu(n);

    // 同一个词出现在多个句子中，则这些句子连通
    for (int w = 1; w <= m; w++) {
        if ((int) occ[w].size() >= 2) {
            int s0 = occ[w][0];
            for (int i = 1; i < (int) occ[w].size(); i++) {
                dsu.unite(s0, occ[w][i]);
            }
        }
    }

    vector<int> comp_sz(n, 0);
    for (int i = 0; i < n; i++) comp_sz[dsu.find(i)]++;

    vector<char> active(n, 0); // 连通块大小>=2 才是“关联组”
    for (int i = 0; i < n; i++) {
        int r = dsu.find(i);
        if (comp_sz[r] >= 2) active[r] = 1;
    }

    const int INF = 1e9;
    vector<int> mn(n, INF); // 每个关联组最小词
    vector<char> in_active(m + 1, 0); // 是否属于某个关联组

    for (int i = 0; i < n; i++) {
        int r = dsu.find(i);
        if (!active[r]) continue;
        for (auto &w: sen[i]) {
            mn[r] = min(mn[r], w);
            in_active[w] = 1;
        }
    }

    vector<int> ans;

    // 每个关联组取最小词，保证字典序最小
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i && active[i] && mn[i] != INF) {
            ans.emplace_back(mn[i]);
        }
    }

    // 不在任何关联组中的词都可选
    for (int w = 1; w <= m; w++) {
        if (!in_active[w]) ans.emplace_back(w);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
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
