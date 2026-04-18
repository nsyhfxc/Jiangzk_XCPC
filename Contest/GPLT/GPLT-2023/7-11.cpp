#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int k;
    cin >> k;
    int n = 1 << k;

    vector<i32> los(2 * n, 0), f(2 * n, (i32)4e18), ans(n, 0);

    for (int i = 1; i <= k; i++) {
        int dep = k - i;
        int L = 1 << dep;
        int cnt = 1 << dep;
        for (int j = 0; j < cnt; j++) {
            cin >> los[L + j];
        }
    }

    i32 w;
    cin >> w;

    for (int i = n; i < 2 * n; i++) {
        f[i] = 1;
    }

    for (int u = n - 1; u >= 1; u--) {
        i32 l = los[u];
        i32 fl = f[u << 1], fr = f[u << 1 | 1];

        if (l >= fl && l >= fr) {
            f[u] = l;
        } else if (l >= fl) {
            f[u] = fr;
        } else if (l >= fr) {
            f[u] = fl;
        } else {
            f[u] = (i32)4e18;
        }
    }

    if (w < f[1]) {
        cout << "No Solution" << endl;
        return;
    }

    function<void(int, i32)> dfs = [&](int u, i32 x) {
        if (u >= n) {
            ans[u - n] = x;
            return;
        }

        i32 l = los[u];
        i32 fl = f[u << 1], fr = f[u << 1 | 1];

        if (x == l) {
            dfs(u << 1, l);
            dfs(u << 1 | 1, l);
            return;
        }

        if (fl <= x && fr <= l) {
            dfs(u << 1, x);
            dfs(u << 1 | 1, l);
        } else {
            dfs(u << 1, l);
            dfs(u << 1 | 1, x);
        }
    };

    dfs(1, w);

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
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