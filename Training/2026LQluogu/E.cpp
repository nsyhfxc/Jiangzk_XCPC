#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n + 1);

    for (int len = 1; len <= n; len++) {
        vector<int> belong(len + 1);
        int res = 0;

        auto check = [&]() {
            vector<set<int>> st(m + 1);

            for (int i = 1; i <= len; i++) {
                int p = belong[i];
                if (st[p].count(a[i])) {
                    return false;
                }
                st[p].insert(a[i]);
            }

            return true;
        };

        function<void(int)> dfs = [&](int pos) {
            if (pos == len + 1) {
                if (check()) {
                    res++;
                    if (res >= MOD) res -= MOD;
                }
                return;
            }

            for (int p = 1; p <= m; p++) {
                belong[pos] = p;
                dfs(pos + 1);
            }
        };

        dfs(1);
        ans[len] = res;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
