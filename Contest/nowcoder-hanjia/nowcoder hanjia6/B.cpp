#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

void solve() {
    int n, x, t;
    cin >> n >> x >> t;
    i32 ans;
    auto ksm = [&](i32 a, i32 b)-> i32 {
        i32 res = 1;
        a = a % MOD;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res % MOD;
    };
    auto Cb = [&](i32 a, i32 b)->i32 {
        if (b < 0 || b > a) return 0;
        b = min(b, a - b);
        i32 res = 1;
        for (i32 i = 1; i <= b; ++i) {
            i32 num = a - b + i;
            i32 den = i;
            i32 g = std::gcd(num, den);
            num /= g;
            den /= g;
            res = (res / den) * num % MOD;
        }
        return res;
    };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
