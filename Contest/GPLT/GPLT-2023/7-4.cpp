#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == a * b) {
        cout << "Lv Yan" << endl;
    }else if (c == a + b) {
        cout << "Tu Dou" << endl;
    }else cout << "zhe du shi sha ya!" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
