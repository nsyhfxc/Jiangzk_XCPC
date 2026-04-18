#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

void solve() {
    i32 n, w, m;
    cin >> n >> m >> w;
    vector<i32> h(n);
    i32 mn = 2e18, mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        mn = min(mn, h[i]);
        mx = max(mx, h[i]);
    }

    i32 l = mn;
    i32 r = mx + m;
    i32 ans = l;
    auto check = [&](i32 tgt)-> bool {
        vector<i32> diff(n + 1, 0);
        i32 cur = 0;
        i32 used = 0;
        for (int i = 0; i < n; ++i) {
            cur += diff[i];
            i32 act = h[i] + cur;
            if (act < tgt) {
                i32 need = tgt - act;
                used += need;
                if (used > m) return false;
                cur += need;
                if (i + w < n) {
                    diff[i + w] -= need;
                }
            }
        }
        return used <= m;
    };
    while (l <= r) {
        const i32 mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
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
