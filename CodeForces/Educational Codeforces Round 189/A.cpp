#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    i64 x, y;
    cin >> x >> y;

    auto check = [&](i64 q) {
        return q * x < y;
    };

    i64 l = 1, r = y / x;
    i64 q = 1;

    while (l <= r) {
        const i64 mid = (l + r) / 2;
        if (check(mid)) {
            q = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    i64 z = q * x;
    if (z > x && z < y && y % z != 0) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
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
