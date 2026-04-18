#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

void solve() {
    i32 n, q, s;
    cin >> n >> q >> s;
    vector<i32> t(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    vector<i32> sum(n + 1);
    sum[1] = s;
    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + t[i - 1];
    }
;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << sum[x] + y - 1 << endl;
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
}
