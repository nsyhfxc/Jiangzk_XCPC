#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b == 0) {
        if (a >= 35 && c >= 33) {
            cout << "Shi Nei\n" << a << "\n";
        } else {
            cout << "Shu Shi\n" << c << "\n";
        }
    } else {
        if (a >= 35 && c >= 33) {
            cout << "Bu Tie\n" << a << "\n";
        } else {
            cout << "Bu Re\n" << c << "\n";
        }
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
