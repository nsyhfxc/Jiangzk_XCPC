#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
constexpr int MOD = 1000000007;
// int main() {
//     i32 n;
//     cin >> n;
//     i32 up = 1;
//     i32 down = 0;
//     for (i32 i = 1; i <= n; ++i) {
//         const i32 next_up = (up * 3 + down * 1) % MOD;
//         const i32 next_down = (up * 1 + down * 3) % MOD;
//         up = next_up % MOD;
//         down = next_down % MOD;
//     }
//     cout << up << endl;
//     return 0;
// }
int main() {
    i32 n;
    cin >> n;
    auto ksm = [&](i32 a, i32 b)-> i32 {
        i32 res = 1;
        a %= MOD;
        while (b) {
            if (b & 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    };
    auto inv = [&](i32 a)-> i32 {
        return ksm(a, MOD - 2);
    };
    i32 ans = (ksm(4, n) + ksm(2, n)) % MOD;
    ans = (ans * inv(2)) % MOD;

    cout << ans << endl;
    return 0;
}
