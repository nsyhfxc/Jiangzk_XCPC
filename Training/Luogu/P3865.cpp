#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int f[N][22];
int lg[N];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i][0]);
    }
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; j <= lg[n]; ++j)
        for (int i = 1; i <= n - (1 << j) + 1; ++i)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);

    for (int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        int j = lg[r - l + 1];
        printf("%d\n", max(f[l][j], f[r - (1 << j) + 1][j]));
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    solve();
    return 0;
}
