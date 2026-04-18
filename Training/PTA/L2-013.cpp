#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct DSU {
    vector<int> fa, sz;

    explicit DSU(int n) {
        init(n);
    }

    void init(int n) {
        fa.resize(n);
        sz.assign(n, 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (x == fa[x]) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }

    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (sz[ra] < sz[rb]) swap(ra, rb);
        fa[rb] = ra;
        sz[ra] += sz[rb];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    int k;
    cin >> k;
    vector<int> lost(k);
    for (int i = 0; i < k; i++) cin >> lost[i];

    vector<int> alive(n, 1);

    auto get_cc = [&](const vector<int> &st) -> int {
        DSU dsu(n);
        for (auto &[u, v]: edges) {
            if (st[u] && st[v]) dsu.unite(u, v);
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!st[i]) continue;
            int r = dsu.find(i);
            if (!vis[r]) {
                vis[r] = 1;
                cnt++;
            }
        }
        return cnt;
    };

    int cur_cc = get_cc(alive);
    int lost_cnt = 0;

    for (int city: lost) {
        vector<int> nxt = alive;
        nxt[city] = 0;

        int nxt_cc = get_cc(nxt);

        if (nxt_cc > cur_cc) {
            cout << "Red Alert: City " << city << " is lost!" << endl;
        } else {
            cout << "City " << city << " is lost." << endl;
        }

        alive[city] = 0;
        cur_cc = nxt_cc;
        lost_cnt++;
    }

    if (lost_cnt == n) {
        cout << "Game Over." << endl;
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
