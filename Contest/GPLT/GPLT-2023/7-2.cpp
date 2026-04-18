#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << a + b - 16 << endl;
    cout << a + b - 3 << endl;
    cout << a + b - 1 << endl;
    cout << a + b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
