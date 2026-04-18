#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (k-- && (a != b || b != c || c != a)) {
        int tmpa = a, tmpb = b, tmpc = c;
        a = floor((tmpb + tmpc) / 2);
        b = floor((tmpa + tmpc) / 2);
        c = floor((tmpa + tmpb) / 2);
    }
    cout << a << " " << b << " " << c << endl;
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
