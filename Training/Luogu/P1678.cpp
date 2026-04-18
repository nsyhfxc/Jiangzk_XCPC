#include<bits/stdc++.h>
using namespace std;
long long int n, m, a[1000005], b[1000005], ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) {
        int k = lower_bound(a + 1, a + n + 1, b[i]) - a;
        if (k == n + 1) {
            ans += b[i] - a[n];
            continue;
        }
        if (k == 1) {
            ans += a[1] - b[i];
            continue;
        }
        ans += min(abs(a[lower_bound(a + 1, a + n + 1, b[i]) - a - 1] - b[i]),
                   abs(a[lower_bound(a + 1, a + n + 1, b[i]) - a] - b[i]));
    }
    cout << ans;
    return 0;
}
