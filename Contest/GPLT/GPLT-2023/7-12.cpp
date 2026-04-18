#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    vector<int> vis(n * m, 0);
    auto id = [&](int x, int y) {
        return x * m + y;
    };

    int ans = 0, treasure = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    auto bfs = [&](int sx, int sy) {
        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        vis[id(sx, sy)] = 1;
        bool has = (g[sx][sy] >= '2' && g[sx][sy] <= '9');

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (g[nx][ny] == '0') continue;
                int p = id(nx, ny);
                if (vis[p]) continue;
                vis[p] = 1;
                if (g[nx][ny] >= '2' && g[nx][ny] <= '9') has = true;
                q.emplace(nx, ny);
            }
        }
        return has;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '0' && !vis[id(i, j)]) {
                ans++;
                if (bfs(i, j)) treasure++;
            }
        }
    }

    cout << ans << " " << treasure << endl;
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