#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

void solve() {
    i32 m, n, z;
    cin >> m >> n >> z;
    if (m >= z) {
        cout << "0";
        return;
    }
    i32 rem = z - m;
    i32 p = m + n;
    i32 remp = rem % p;
    if (remp > 0 && remp <= n) {
        cout << "1";
    } else {
        cout << "0";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
