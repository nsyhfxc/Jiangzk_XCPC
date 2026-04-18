#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 100010;
int n, m, s, a, b, c;
vector<pair<int, int> > e[MAXN];
int d[MAXN], vis[MAXN];

void dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    priority_queue<pair<int, int> > q;
    q.emplace(0, s);
    while (q.size()) {
        const auto u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,w]: e[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.emplace(-d[v], v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a].emplace_back(b, c);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) printf("%d ", d[i]);
}
