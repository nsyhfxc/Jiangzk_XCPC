#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<i64> a(n + 1);
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    while (m--) {
        i64 k;
        cin >> k;
        vector<i64> d(n + 1), pre(n + 1);
        for (int i = 1; i <= n; i++) {
            d[i] = (a[i] ^ k) - a[i];
            pre[i] = pre[i - 1] + d[i];
        }
        i64 mn = 0, mx = 0;
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                i64 cur = pre[r] - pre[l - 1];
                mn = min(mn, cur);
                mx = max(mx, cur);
            }
        }

        cout << sum + mn << ' ' << sum + mx << endl;
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
