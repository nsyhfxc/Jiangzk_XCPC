#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 101;
int g[MAXN][MAXN];
int n, m, ans = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(const int &x, const int &y) {
    g[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) { //超出边界
            continue;
        }
        if (g[nx][ny] == 0) { //不是符合条件的块
            continue;
        }
        dfs(nx, ny);
    }
}

void bfs(const int &x,const int &y) {
    queue<pair<int, int> > q;
    q.emplace(x, y);
    g[x][y] = 0;
    while (!q.empty()) {
        const auto &p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (g[nx][ny] == 0) {
                continue;
            }
            g[nx][ny] = 0;
            q.emplace(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &g[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] > 0) {
                ans++;
                //dfs(i, j);
                bfs(i, j);
            }
        }
    }
    cout << ans << endl;
}
