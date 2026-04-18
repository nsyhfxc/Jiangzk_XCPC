#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 50010;
int n, siz[MAXN], f[MAXN], d[MAXN], cnt = 1e9, v, sum;
vector<int> e[MAXN];

void dfs(const int &u, const int &fa) {
    siz[u] = 1;
    for (const auto &v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        f[u] = max(f[u], siz[v]);
        siz[u] += siz[v];
    }
    f[u] = max(f[u], n - siz[u]);
    cnt = min(cnt, f[u]);
}

void dfs2(const int &u, const int &fa) {
    for (const auto &v: e[u]) {
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dfs2(v, u);
    }
    sum += d[u];
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        if (f[i] == cnt) {
            v = i;
            break;
        }
    dfs2(v, 0);
    cout << v << " " << sum << endl;
    return 0;
}
