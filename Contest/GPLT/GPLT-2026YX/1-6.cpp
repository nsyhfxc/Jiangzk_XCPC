#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    i32 n;
    cin >> n;
    i32 a = 0, b = 0, c = 0;
    for (i32 i = 2; i * i * i <= n; i++) {
        if (n % i == 0) {
            a = i;
            break;
        }
    }
    if (a == 0) {
        cout << "NO" << endl;
        return;
    }
    i32 rem = n / a;
    for (i32 i = a + 1; i * i <= rem; i++) {
        if (rem % i == 0) {
            b = i;
            break;
        }
    }
    if (b == 0) {
        cout << "NO" << endl;
        return;
    }
    c = rem / b;
    if (c > 2 && c != a && c != b) {
        cout << "YES" << endl;
        cout << a << " " << c << " " << b << endl;
    } else {
        cout << "NO" << endl;
    }
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
