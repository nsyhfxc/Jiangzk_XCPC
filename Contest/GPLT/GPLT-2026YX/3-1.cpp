#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'
constexpr int mod = 1e9 + 7;
constexpr int MAXN = 1000005;
i32 primes[MAXN], cnt = 0;
bool st[MAXN];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

i32 count(i32 e) {
    i32 total = (e + 2) * (e + 1) / 2;
    i32 invalid = 0;
    if (e >= 3) {
        invalid = (e - 1) * (e - 2) / 2;
    }
    return (total - invalid) % mod;
}

void solve() {
    i32 x;
    cin >> x;

    if (x == 1) {
        cout << 1 << endl;
        return;
    }
    i32 ans = 1;
    for (i32 i = 0; i < cnt && primes[i] * primes[i] <= x; i++) {
        if (x % primes[i] == 0) {
            int e = 0;
            while (x % primes[i] == 0) {
                e++;
                x /= primes[i];
            }
            ans = (ans * count(e)) % mod;
        }
    }
    if (x > 1) {
        ans = (ans * count(1)) % mod;
    }

    cout << (ans + mod) % mod << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init(1000000);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
