#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 1));
    while (q--) {
        int t, c;
        cin >> t >> c;
        if (t == 0) {
            for (int j = 1; j <= m; j++) {
                arr[c][j] = 0;
            }
        } else {
            for (int i = 1; i <= n; i++) {
                arr[i][c] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += arr[i][j];
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}