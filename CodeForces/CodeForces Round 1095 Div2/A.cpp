#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define endl '\n'

void solve() {
    int x, y;
    cin >> x >> y;
    // x是偶数，y是偶数 -> 肯定可以
    // x 或 y 有一个是偶数 -> 肯定可以
    // x 或 y 都是奇数 ->肯定不可以
    bool ok = true;
    if (x & 1 && y & 1) {
        ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
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
