#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

void solve() {
    i32 n, m, l;
    cin >> n >> m >> l;
    vector<i32> arr(n), sum(n);
    for (i32 i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sum[0] = arr[0];
    for (i32 i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    auto check = [&](const i32 &p)-> bool {
        auto it = upper_bound(sum.begin(), sum.end(), p);
        return it != sum.end() && *it < p + l;
    };

    bool ok = check(0);
    i32 pos = 0;
    for (int i = 0; i < m; ++i) {
        i32 y;
        cin >> y;
        pos += y;
        if (ok == false && check(pos)) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
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
