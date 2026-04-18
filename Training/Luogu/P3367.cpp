#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

struct DSU {
    vector<int> fa;

    explicit DSU(const int &n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) return;
        fa[rootx] = rooty;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= m; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            dsu.merge(x, y);
        } else if (z == 2) {
            if (dsu.same(x, y)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
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
    return 0;
}
