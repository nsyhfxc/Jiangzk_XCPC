#include<bits/stdc++.h>
using namespace std;
constexpr int N = 100;
int g[N][N];
int n, m, t, sx, sy, fx, fy;
int a, b, ans = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(const int &x, const int &y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        const int nx = x + dx[i];
        const int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        }
        if (g[nx][ny]) continue;
        g[x][y] = 1;
        dfs(nx, ny);
        g[x][y] = 0;
    }
}

void solve() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        g[a][b] = 1;
    }
    g[sx][sy] = 1;
    dfs(sx, sy);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
