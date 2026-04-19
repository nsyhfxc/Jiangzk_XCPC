#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;
#define endl '\n'

struct matrix {
    ll c[101][101]{};

    matrix() {
        memset(c, 0, sizeof(c));
    }
} A, res;

ll n, k;

matrix operator*(const matrix &x, const matrix &y) {
    matrix t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % MOD;
            }
        }
    }
    return t;
}

void ksm(ll &k) {
    for (int i = 1; i <= n; i++) {
        res.c[i][i] = 1;
    }
    while (k) {
        if (k & 1) res = res * A;
        A = A * A;
        k >>= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A.c[i][j];
        }
    }
    ksm(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << res.c[i][j] << " ";
        }
        cout << endl;
    }
}
