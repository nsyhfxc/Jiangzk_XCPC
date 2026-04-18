#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    i32 n, p;
    cin >> n >> p;
    if (n == 1) {
        cout << 1 % p << endl;
        return;
    }

    int lim = (int) min<i32>(n, (i32) (powl((long double) n, 2.0L / 3.0L) + 5));
    lim = max(lim, 1);

    vector<signed char> mu(lim + 1);
    vector<char> vis(lim + 1);
    vector<int> primes;
    mu[1] = 1;

    for (int i = 2; i <= lim; i++) {
        if (!vis[i]) {
            primes.emplace_back(i);
            mu[i] = -1;
        }
        for (int j = 0; j < (int) primes.size(); j++) {
            int pr = primes[j];
            i32 x = 1LL * i * pr;
            if (x > lim) break;
            vis[(int) x] = 1;
            if (i % pr == 0) {
                mu[(int) x] = 0;
                break;
            }
            mu[(int) x] = -mu[i];
        }
    }

    vector<int> pre(lim + 1);
    for (int i = 1; i <= lim; i++) {
        pre[i] = pre[i - 1] + mu[i];
    }

    vector<signed char>().swap(mu);
    vector<char>().swap(vis);
    vector<int>().swap(primes);

    unordered_map<i32, i32> mp;
    mp.reserve((size_t) (n / max<i32>(1LL, lim) * 4 + 100));
    mp.max_load_factor(0.7f);

    function<i32(i32)> getM = [&](i32 x) -> i32 {
        if (x <= lim) return pre[(int) x];
        auto it = mp.find(x);
        if (it != mp.end()) return it->second;

        i32 res = 1;
        for (i32 l = 2, r; l <= x; l = r + 1) {
            i32 q = x / l;
            r = x / q;
            res -= (r - l + 1) * getM(q);
        }
        mp.emplace(x, res);
        return res;
    };

    u32 mod = (u32) p;
    auto mul = [&](u32 a, u32 b) -> u32 {
        return (u32) ((__int128) a * b % mod);
    };
    auto qpow = [&](u32 a, i32 b) -> u32 {
        u32 res = 1 % mod;
        while (b) {
            if (b & 1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    };
    auto sub = [&](u32 a, u32 b) -> u32 {
        return a >= b ? a - b : a + mod - b;
    };
    auto norm = [&](i32 x) -> u32 {
        return x >= 0 ? (u32) x : (u32) (x + p);
    };

    u32 ans = 1 % mod;
    i32 pw = p - 2;
    i32 last = 1; // M(1)

    for (i32 l = 2, r; l <= n; l = r + 1) {
        i32 m = n / l;
        r = n / m;

        i32 cur = getM(r);
        i32 coef = cur - last; // sum_{d=l}^r mu(d)
        last = cur;

        if (coef == 0) continue;

        u32 inv = qpow((u32) (n - m), pw);
        u32 val = mul((u32) m, inv);
        ans = sub(ans, mul(norm(coef), val));
    }

    cout << ans << endl;
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
