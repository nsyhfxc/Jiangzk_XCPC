#include <bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve() {
    int n;
    cin >> n;
    vector mapp(n + 1, vector(n + 1, 0));
    vector visited(n + 1, vector(n + 1, false)); //标记数组

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mapp[i][j];
        }
    }

    i32 mx = -2e18;
    function<void(int, int, i32)> dfs = [&](const int &x, const int &y, const i32 &sum) {
        if (x == n && y == n) {
            mx = max(mx, sum);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(nx, ny, sum + mapp[nx][ny]);
                visited[nx][ny] = false;
            }
        }
    };

    visited[1][1] = true;
    dfs(1, 1, mapp[1][1]);

    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
