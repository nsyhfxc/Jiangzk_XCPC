#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a, b, m, phi, flag;
constexpr int N = 20000005;
char s[N];

int get_phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) res = res / n * (n - 1);
    return res;
}

int depow(int phi) {
    int b = 0;
    for (int i = 0; s[i]; i++) {
        b = b * 10 + (s[i] - '0');
        if (b >= phi) flag = 1, b %= phi;
    }
    if (flag) b += phi;
    return b;
}

int ksm(ll a, ll b) {
    int res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> a >> m >> s;
    phi = get_phi(m);
    b = depow(phi);
    cout << ksm(a, b) << endl;
    return 0;
}
