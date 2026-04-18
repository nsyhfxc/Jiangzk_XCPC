#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i - j]) % 100003;
            }
        }
    }
    cout << dp[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
