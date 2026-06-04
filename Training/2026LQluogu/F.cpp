#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

const int MOD = 998244353;

void solve() {
    int n, m, P;
    cin >> n >> m >> P;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    struct Edge {
        int x, y, k;
    };

    vector<Edge> edges;
    edges.reserve(m);

    for (int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        edges.push_back({x, y, k});
    }
    vector<vector<int> > dp(P + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        if (a[i] <= P) {
            dp[a[i]][i]++;
        }
    }

    vector<int> ans(n + 1, 0);

    for (int cost = 0; cost <= P; cost++) {
        for (int i = 1; i <= n; i++) {
            ans[i] += dp[cost][i];
            if (ans[i] >= MOD) ans[i] -= MOD;
        }

        for (auto [x, y, k]: edges) {
            if (cost + k > P) continue;
            if (dp[cost][x] == 0) continue;

            dp[cost + k][y] += dp[cost][x];
            if (dp[cost + k][y] >= MOD) {
                dp[cost + k][y] -= MOD;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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

    return 0;
}
