#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    int cnt = 0;
    for (int i = x; i <= y; i++) {
        if (x * y % i == 0 && gcd(i, x * y / i) == x) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
