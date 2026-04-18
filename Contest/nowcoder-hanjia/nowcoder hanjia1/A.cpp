#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353
#define N 10
int S[N];

i32 ksm(i32 a, i32 b, const i32 mod) {
    i32 ans = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

i32 inv100 = ksm(100LL, MOD - 2, MOD); //乘法逆元，计算除以100

void init() {
    S[0] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 4) | (1 << 5) | (1 << 6);
    S[1] = (1 << 2) | (1 << 5);
    S[2] = (1 << 0) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 6);
    S[3] = (1 << 0) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);
    S[4] = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5);
    S[5] = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 5) | (1 << 6);
    S[6] = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
    S[7] = (1 << 0) | (1 << 2) | (1 << 5);
    S[8] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) |
           (1 << 6);
    S[9] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);
} // 这里用到了状态压缩的技巧，把亮灯的不同情况用二进制数来储存

void solve() {
    int C;
    cin >> C;
    vector<i32> p(7); // 每个灯管发亮的概率
    for (int i = 0; i < 7; i++) {
        cin >> p[i];
        p[i] = (1LL * p[i] % MOD) * (inv100 % MOD) % MOD;
    }
    vector<i32> digit(10, 1); // 记录0-9的概率
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 7; j++) {
            if (S[i] >> j & 1) {
                digit[i] *= p[j];
            } else {
                digit[i] *= (1 + MOD - p[j]);
            }
            digit[i] %= MOD;
        }
    }
    auto calc = [&](int x) -> i32 {
        // 求某一排显示器显示出x的概率
        if (x == 0) {
            return digit[0] * digit[0] % MOD * digit[0] % MOD * digit[0] %
                   MOD;
        }
        i32 ans = 1;
        int len = 0;
        while (x) {
            ans *= digit[x % 10];
            ans %= MOD;
            x /= 10;
            len++;
        }
        for (int i = 1; i <= 4 - len; i++) {
            ans = (ans * digit[0]) % MOD;
        }
        return ans;
    };
    int ans = 0;
    for (int A = 0; A <= C; A++) {
        int B = C - A;
        ans += 1LL * calc(A) * calc(B) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    init();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
