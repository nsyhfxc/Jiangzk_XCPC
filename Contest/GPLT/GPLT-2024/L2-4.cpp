#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

const int N = 5;

int n, k, ans, row[N], col[N];

void solve() {
    auto dfs = [&](auto &&self, int x, int y) -> void {
        if (x == n && y > n) {
            for (int i = 1; i <= n; i++) {
                if (row[i] != k) return;
            }
            for (int i = 1; i <= n; i++) {
                if (col[i] != k) return;
            }
            ans++;
            return;
        }
        if (y > n) {
            x++;
            y = 1;
        }
        for (int i = 0; row[x] + i <= k && col[y] + i <= k; i++) {
            // 剪枝1 行/列和不超过k
            if (row[x] + i + k * (n - y) < k || col[y] + i + k * (n - x) < k) continue; // 剪枝2 可以达到k
            row[x] += i;
            col[y] += i;
            self(self, x, y + 1);
            row[x] -= i;
            col[y] -= i;
        }
    };

    dfs(dfs, 1, 1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> k >> n;
        solve();
    }
    return 0;
}
