#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
constexpr int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;

    vector arr(n + 2, vector<i32>(m + 2, 0));//原始
    vector diff(n + 2, vector<i32>(m + 2, 0));//差分

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        i32 c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        diff[x1][y1] += c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            i32 h = arr[i][j] + diff[i][j];
            i32 sq = (h % MOD) * (h % MOD) % MOD;
            arr[i][j] = (sq + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + MOD) % MOD;
        }
    }

    //先找差分，先处理差分，确定好增量是多少，增量求前缀和，再求前缀和
    int Q;
    cin >> Q;
    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        i32 ans = (arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] + 2LL * MOD) % MOD;
        cout << ans << "\n";
    }

    return 0;
}
