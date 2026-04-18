#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
constexpr i32 inf = 1e18;

struct Edge {
    int to;
    i32 w;
};

struct Node {
    int u;
    int k;
    int state;
    i32 dist;

    bool operator>(const Node &other) const {
        return dist > other.dist;
    }
};

void solve() {
    int n, m, k, s, e;
    cin >> n >> m >> k >> s >> e;
    vector<vector<Edge> > adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        i32 w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector dist(n + 1, vector(k + 1, vector<i32>(2, inf)));
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    dist[s][0][0] = 0;
    pq.push({s, 0, 0, 0});
    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.dist > dist[curr.u][curr.k][curr.state]) continue;
        if (curr.u == e) {
            cout << curr.dist << endl;
            return;
        }

        for (auto &edge: adj[curr.u]) {
            int v = edge.to;
            i32 w = edge.w;
            if (curr.state == 0) {
                if (dist[v][curr.k][0] > curr.dist + w) {
                    dist[v][curr.k][0] = curr.dist + w;
                    pq.push({v, curr.k, 0, dist[v][curr.k][0]});
                }
                if (curr.k < k && dist[v][curr.k + 1][1] > curr.dist) {
                    dist[v][curr.k + 1][1] = curr.dist;
                    pq.push({v, curr.k + 1, 1, dist[v][curr.k + 1][1]});
                }
            } else {
                if (dist[v][curr.k][0] > curr.dist + 2 * w) {
                    dist[v][curr.k][0] = curr.dist + 2 * w;
                    pq.push({v, curr.k, 0, dist[v][curr.k][0]});
                }
            }
        }
    }
    i32 ans = inf;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, min(dist[e][i][0], dist[e][i][1]));
    }

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
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
