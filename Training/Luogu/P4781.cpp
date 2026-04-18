#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
ll n, k, ans;
ll x[2005], y[2005];

ll quickpow(ll a,ll b) {
    ll s = 1;
    while (b) {
        if (b & 1)s = s * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return s;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) {
        ll a = y[i], b = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            a = a * (k - x[j]) % mod;
            b = b * (x[i] - x[j]) % mod;
        }
        ans = (ans + a * quickpow(b, mod - 2) % mod) % mod;
    }
    cout << (ans + mod) % mod;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
