#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

int dx[] = {0, 0, 0, 1, -1, 1, 1, -1, -1, 0, 0, 2, -2};
int dy[] = {0, 1, -1, 0, 0, 1, -1, 1, -1, 2, -2, 0, 0};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector arr(n + 1, vector<i32>(m + 1, 0));
    vector sum(n + 1, vector<i32>(m + 1, 0));

    for (i32 i = 1; i <= n; i++) {
        for (i32 j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    i32 mx = -1;
    int resx = 1, resy = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0) continue;
            for (int k = 0; k < 13; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                    sum[nx][ny] += arr[i][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sum[i][j] > mx) {
                mx = sum[i][j];
                resx = i;
                resy = j;
            }
        }
    }

    while (q--) {
        i32 x, y, z;
        cin >> x >> y >> z;
        for (int i = 0; i < 13; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                sum[nx][ny] += z;
                if (sum[nx][ny] > mx) {
                    mx = sum[nx][ny];
                    resx = nx;
                    resy = ny;
                }
            }
        }
        cout << resx << " " << resy << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
