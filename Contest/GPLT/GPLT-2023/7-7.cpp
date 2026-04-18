#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    i32 n0, n1, n;
    cin >> n0 >> n1 >> n;
    i32 ans0 = -1, ans1 = -1;
    i32 best = (1LL << 60);

    for (i32 x = 1; x < n; x++) {
        i32 y = n - x;
        if (n0 % x != 0 || n1 % y != 0) continue;

        i32 a = n0 / x;
        i32 b = n1 / y;

        if (a < 2 || b < 2) continue;

        i32 diff = llabs(a - b);
        if (diff < best) {
            best = diff;
            ans0 = x;
            ans1 = y;
        }
    }

    if (ans0 == -1) {
        cout << "No Solution" << endl;
    } else {
        cout << ans0 << ' ' << ans1 << endl;
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
