#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

const int N = 10;
int grid[N][N];
int n = 9;

void solve() {
    auto check1 = [&]() -> bool {
        for (int i = 1; i <= n; i++) {
            vector<bool> vis(10, false);
            for (int j = 1; j <= n; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9) return false;
                if (vis[grid[i][j]]) return false;
                vis[grid[i][j]] = true;
            }
            for (int k = 1; k <= 9; k++) if (!vis[k]) return false;
        }
        return true;
    };

    auto check2 = [&]() -> bool {
        for (int i = 1; i <= n; i++) {
            vector<bool> vis(10, false);
            for (int j = 1; j <= n; j++) {
                if (grid[j][i] < 1 || grid[j][i] > 9) return false;
                if (vis[grid[j][i]]) return false;
                vis[grid[j][i]] = true;
            }
            for (int k = 1; k <= 9; k++) if (!vis[k]) return false;
        }
        return true;
    };

    auto check3 = [&]() -> bool {
        for (int sx = 1; sx <= n; sx += 3) {
            for (int sy = 1; sy <= n; sy += 3) {
                vector<bool> vis(10, false);
                for (int i = sx; i <= sx + 2; i++) {
                    for (int j = sy; j <= sy + 2; j++) {
                        if (grid[i][j] < 1 || grid[i][j] > 9) return false;
                        if (vis[grid[i][j]]) return false;
                        vis[grid[i][j]] = true;
                    }
                }
                for (int k = 1; k <= 9; k++) if (!vis[k]) return false;
            }
        }
        return true;
    };

    cout << (check1() && check2() && check3() ? "1" : "0") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> grid[i][j];
            }
        }
        solve();
    }
    return 0;
}
