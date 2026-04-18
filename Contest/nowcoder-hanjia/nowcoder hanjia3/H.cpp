#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using db = double;
using namespace std;

void solve() {
    i32 xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    const i32 p1 = xa * yb - xb * ya;
    const i32 p2 = ya - yb;
    cout << fixed << setprecision(10);
    if (p2 == 0) {
        if (abs(p1) == 4) {
            cout << 0.0 << endl;
        } else {
            cout << "no answer" << endl;
        }
    } else {
        cout << (4.0 - static_cast<double>(p1)) / static_cast<double>(p2) << endl;
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
