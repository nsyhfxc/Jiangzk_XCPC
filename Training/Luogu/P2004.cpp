#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1024][1024];
int sum[1024][1024];
int ux, uy;
int n, m, c;
int ans;

signed main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (i + c - 1 > n || j + c - 1 > m) continue;
            if (sum[i + c - 1][j + c - 1] - sum[i - 1][j + c - 1] - sum[i + c - 1][j - 1] + sum[i - 1][j - 1] > ans) {
                ans = sum[i + c - 1][j + c - 1] - sum[i - 1][j + c - 1] - sum[i + c - 1][j - 1] + sum[i - 1][j - 1];
                ux = i, uy = j;
            }
        }
    cout << ux << " " << uy << endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
