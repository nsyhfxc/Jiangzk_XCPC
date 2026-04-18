#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct Edge {
    int u, v;
};

void solve() {
    int n, m, k;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v;
    }
    cin >> k;
    while (k--) {
        int np, city;
        cin >> np;
        vector<bool> broken(n + 1, false);
        for (int i = 0; i < np; i++) {
            cin >> city;
            broken[city] = true;
        }
        bool ok = true;
        for (const auto &e: edges) {
            if (!broken[e.u] && !broken[e.v]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
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
