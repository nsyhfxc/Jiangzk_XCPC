#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int x = 0; x < n; x++) {
        queue<char> que;
        for (int y = 0; y < m; y++) {
            bool flag = false;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (a[nx][ny] == a[x][y]) {
                    flag = true;
                    break;
                }

                for (int j = 0; j < 4; j++) {
                    int nx2 = nx + dx[j], ny2 = ny + dy[j];
                    if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m) continue;
                    if (nx2 == x && ny2 == y) continue;
                    if (a[nx2][ny2] == a[x][y]) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) {
                que.push('Y');
            } else que.push('N');
        }
        while (!que.empty()) {
            cout << que.front();
            que.pop();
        }
        cout << endl;
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
