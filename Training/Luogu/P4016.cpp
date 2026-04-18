#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, rt, d[N];
vector<pair<int, int> > e[N];

void solve() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        e[x].emplace_back(y, 1);
        e[y].emplace_back(x, 1);
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
        if (d[rt] < d[u]) rt = u;
        for (auto [v, w]: e[u]) {
            if (v == fa) continue;
            d[v] = d[u] + w;
            self(self, v, u);
        }
    };


    dfs(dfs, 1, 0);
    d[rt] = 0;
    dfs(dfs, rt, 0);
    cout << d[rt];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
