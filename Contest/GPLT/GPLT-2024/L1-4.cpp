#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    i32 n, m, sum = 0;
    cin >> n >> m;
    for (i32 i = 1, x; i <= m; i++) {
        cin >> x;
        sum += x;
    }
    if (sum == n * m) {
        cout << n << endl;
    } else if (n > sum) {
        cout << 0 << endl;
    } else {
        cout << sum - (sum / n) * n << endl;
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
