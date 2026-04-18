#include<bits/stdc++.h>
using namespace std;

void solve() {
    double h, w;
    cin >> h >> w;
    double sw = (h - 100) * 0.9;
    w /= 2;
    if (abs(w - sw) < sw * 0.1) {
        cout << "You are wan mei!" << endl;
    }else if (w - sw > 0) {
        cout << "You are tai pang le!" << endl;
    }else {
        cout << "You are tai shou le!" << endl;
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
}
