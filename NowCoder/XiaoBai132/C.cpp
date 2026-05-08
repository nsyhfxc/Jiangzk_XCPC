#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const 
void solve() {
    i64 l, r;
    cin >> l >> r;
    auto ksm = [&](i64 a, i64 b, i64 MOD)-> i64 {
        i64 res = 1;
        a %= MOD;
        while (b) {
            if (b & 1) {
                res = (res * a) % MOD;
            }
            b >>= 1;
            a = (a * a) % MOD;
        }
        return res;
    };
    for (int i = 0; i <= 63; i++) {
        for (int j = 0; j <= 63; j++) {
            if (ksm(2,i,mod) + )

        }
    }
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
