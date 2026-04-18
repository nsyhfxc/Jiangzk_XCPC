#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    string s;
    cin >> s;
    bool b = true,o = true,d = true,h = true;
    for (auto c : s) {
        if (c == 'A' || c == 'B' || c == 'C' ||c == 'D' ||c == 'E' ||c == 'F') {
            d = false;
            b = false;
            o = false;
        }
        if (c == '8' || c == '9') {
            o = false;
            b = false;
        }
        if (c != '0' && c != '1') {
            b = false;
        }
        if (c > 'F') {
            b = false;
            o = false;
            d = false;
            h = false;
        }
    }
    cout << b << " " << o << " " << d << " " << h << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t--) {
        solve();
    }
    return 0;
}
