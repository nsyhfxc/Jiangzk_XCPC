#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
constexpr i32 mod = 998244353;
#define endl '\n'

void solve() {
    int n, p;
    scanf("%d %d", &n, &p);
    function<i32(i32, i32)> ksm = [&](i32 a, i32 b)-> i32 {
        i32 res = 1;
        a %= p;
        while (b) {
            if (b & 1) {
                res = res * a % p;
            }
            a = a * a % p;
            b >>= 1;
        }
        return res % p;
    };
    function<i32(i32)> inv = [&](i32 a)-> i32 {
        return ksm(a, p - 2) % p;
    };
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", inv(i));
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
