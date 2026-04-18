#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;

struct Edge {
    int u, v, w;

    explicit Edge(const int &u = 0, const int &v = 0, const int &w = 0) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    ~Edge() {}
};

struct cmp {
    bool operator()(const Edge &a, const Edge &b) const {
        return a.w < b.w;
    }
};

int fa[MAXN];
int n, m;
vector<Edge> edges;

int find(const int &x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.emplace_back(x, y, z);
    }
    sort(edges.begin(), edges.end(), cmp());
    long long ans = 0;
    int cnt = 0;
    for (auto &e: edges) {
        const auto fu = find(e.u), fv = find(e.v);
        if (fu != fv) {
            fa[fu] = fv;
            ans += e.w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    if (cnt != n - 1) {
        cout << "orz" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
