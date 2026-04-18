#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
constexpr int mod = 1e9 + 7;
#define endl '\n'

void solve() {
    i32 n;
    cin >> n;
    auto ksm = [&](i32 a, i32 b) {
        i32 res = 1;
        a %= mod;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    };
    auto inv = [&](i32 a) {
        return ksm(a, mod - 2);
    };
    cout << 7 * (ksm(10, n) - 1 + mod) % mod * inv(9) % mod << endl;
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
