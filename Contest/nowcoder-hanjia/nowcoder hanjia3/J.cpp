#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    i32 n, q;
    cin >> n >> q;
    while (q--) {
        i32 x;
        cin >> x;
        i32 d = __lg(x);
        i32 l = 1LL << d;
        i32 r = (1LL << (d + 1)) - 1;
        cout << max(0LL, min(n, r) - l + 1) << endl;
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
