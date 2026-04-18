#include <bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int mn = min({a, b, c});
    a -= mn;
    b -= mn;
    c -= mn;
    if (a >= 2 || b >= 2 || c >= 2) {
        cout << "NO" << endl;
    } else cout << "YES" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
