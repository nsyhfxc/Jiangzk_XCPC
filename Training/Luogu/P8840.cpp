#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, p;
    cin >> a >> p;
    if (p < 16) {
        a -= 10;
        if (a < 0) a = 0;
    } else if (p > 20) {
        a -= (p - 20);
        if (a < 0) a = 0;
    }
    cout << a << endl;
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
