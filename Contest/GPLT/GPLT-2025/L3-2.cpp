#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > s(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    vector<vector<long> > p(2 * n, vector<long>(2 * m));
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 1; j < 2 * m; j++) {
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + max(abs(i - n), abs(j - m));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = 2 * n - 1 - i, y = 2 * m - 1 - j; // 窗口右下角坐标
            cout << s[i][j] * (p[x][y] - p[x - n][y] - p[x][y - m] + p[x - n][y - m]) << " \n"[j == m - 1];
        }
    }
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
