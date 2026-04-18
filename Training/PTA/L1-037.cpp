#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'

void solve() {
    double a, b;
    cin >> a >> b;
    if (b > 0) {
        cout << a << "/" << b << "=" << fixed << setprecision(2) << a/b << endl;
    }else if (b < 0) {
        cout << a << "/(" << b << ")=" << fixed << setprecision(2) << a/b << endl;
    }else cout << a << "/" << b << "=" << "Error" << endl;
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
