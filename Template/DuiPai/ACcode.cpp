#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (k--) {
        int tempa = a;
        int tempb = b;
        int tempc = c;
        //cout << a << " " << b << " " << c << endl;
        a = (tempb + tempc) >> 1;
        b = (tempa + tempc) >> 1;
        c = (tempa + tempb) >> 1;
        if (a == b && b == c) {
            break;
        }
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
