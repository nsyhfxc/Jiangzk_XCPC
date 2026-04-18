#include <bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> f(m + 1, 0);
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= v[i]; --j) {
            f[j] = (f[j] + f[j - v[i]]) % 10;
        }
    }

    for (int i = 0; i < n; ++i) {
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        string res = "";
        for (int j = 1; j <= m; ++j) {
            if (j < v[i]) {
                dp[j] = f[j];
            } else {
                dp[j] = (f[j] - dp[j - v[i]] + 10) % 10;
            }
            res += to_string(dp[j]);
        }
        cout << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
