#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e3 + 10;
int n, m, s[MAXN][MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x++, y++;
        s[x][y] += v;
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int res = 0;
    for (int i = m; i <= 5001; i++) {
        for (int j = m; j <= 5001; j++) {
            res = max(res, s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
        }
    }
    cout << res << endl;
    return 0;
}
