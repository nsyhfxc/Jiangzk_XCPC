#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int mod = 1e9 + 7;

struct mat {
    LL c[3][3];
    mat() {
        memset(c, 0, sizeof c);
    }
};
struct mat F,A;
struct mat operator*(const mat &a, const mat &b) {
    mat t;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k) {
                t.c[i][j] += a.c[i][k] * b.c[k][j] % mod;
                t.c[i][j] %= mod;
            }
    return t;
}

void quickpow(LL n) {
    F.c[0][0] = F.c[0][1] = F.c[0][2] = 1;
    memset(A.c, 0, sizeof(A.c));
    A.c[0][0] = A.c[0][1] = A.c[1][2] = A.c[2][0] = 1;
    while (n) {
        if (n & 1) F = F * A;
        A = A * A;
        n >>= 1;
    }
}

int main() {
    LL t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 3) {
            puts("1");
            continue;
        }
        quickpow(n - 3);
        cout << F.c[0][0] << endl;
    }
}
