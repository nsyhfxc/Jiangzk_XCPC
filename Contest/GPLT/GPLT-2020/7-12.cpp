#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;

    const i32 INF = (1LL << 60);
    vector<vector<i32> > dis(n + 1, vector<i32>(n + 1, INF));
    for (int i = 0; i <= n; i++) dis[i][i] = 0;

    auto add = [&](int u, int v, i32 w) {
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    };

    for (int i = 0; i < m; i++) {
        int u, v;
        i32 w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    int k;
    cin >> k;

    int cnt = 0, ans_id = -1;
    i32 ans = INF;

    for (int id = 1; id <= k; id++) {
        int len;
        cin >> len;

        vector<int> vis(n + 1, 0);
        bool ok = true;
        i32 sum = 0;
        int pre = 0;

        for (int i = 0; i < len; i++) {
            int x;
            cin >> x;

            if (dis[pre][x] == INF) ok = false;
            else sum += dis[pre][x];

            if (x < 1 || x > n || vis[x]) ok = false;
            else vis[x] = 1;

            pre = x;
        }

        if (dis[pre][0] == INF) ok = false;
        else sum += dis[pre][0];

        if (len != n) ok = false;

        if (ok) {
            cnt++;
            if (sum < ans) {
                ans = sum;
                ans_id = id;
            }
        }
    }

    cout << cnt << endl;
    cout << ans_id << ' ' << ans << endl;
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
