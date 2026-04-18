#include<bits/stdc++.h>
using namespace std;
constexpr int N = 101;
char g[N][N];
int n, m, ans = 0;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(const int &x, const int &y) {
    g[x][y] = '.';
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }
        if (g[nx][ny] == '.') {
            continue;
        }
        dfs(nx, ny);
    }
}

void bfs(const int &x, const int &y) {
    queue<pair<int, int> > q;
    q.emplace(x, y);
    g[x][y] = '.';
    while (!q.empty()) {
        const auto &p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (g[nx][ny] == '.') {
                continue;
            }
            g[nx][ny] = '.';
            q.emplace(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W') {
                ans++;
                //dfs(i, j);
                bfs(i, j);
            }
        }
    }
    cout << ans << endl;
}
