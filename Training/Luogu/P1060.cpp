#include<bits/stdc++.h>
using namespace std;
constexpr int N = 3e4 + 10;
int n, m;
int w[N], v[N], f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
        w[i] *= v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            if (j >= v[i]) {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }
    cout << f[m] << endl;
}
