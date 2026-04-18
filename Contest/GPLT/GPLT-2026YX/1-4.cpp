#include <bits/stdc++.h>
#define end '\n'
constexpr int N = 1e6 + 10;
using namespace std;
using i32 = long long;

void solve() {
    i32 n, op;
    cin >> n >> op;
    vector arr(n + 1, vector<char>(n + 1));
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    if (op == 2) {
        for (i32 k = 1; k <= 2 * n - 1; k++) {
            i32 diff = n - k;
            if (k & 1) {
                for (i32 r = n; r >= 1; r--) {
                    i32 c = diff + r;
                    if (c >= 1 && c <= n) {
                        cout << arr[r][c];
                    }
                }
            } else {
                for (i32 r = 1; r <= n; r++) {
                    i32 c = diff + r;
                    if (c >= 1 && c <= n) {
                        cout << arr[r][c];
                    }
                }
            }
        }
    } else {
        for (i32 k = 1; k <= 2 * n - 1; k++) {
            i32 diff = k + 1;
            if (k & 1) {
                for (i32 r = n; r >= 1; r--) {
                    i32 c = diff - r;
                    if (c >= 1 && c <= n) {
                        cout << arr[r][c];
                    }
                }
            } else {
                for (i32 r = 1; r <= n; r++) {
                    i32 c = diff - r;
                    if (c >= 1 && c <= n) {
                        cout << arr[r][c];
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
