#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    i32 n, m, k;
    cin >> n >> m >> k;
    vector<vector<i32> > arr(n, vector<i32>(m));
    for (i32 i = 0; i < n; ++i)
        for (i32 j = 0; j < m; ++j)
            cin >> arr[i][j];
    while (k--) {
        i32 mx = arr[0][0];
        i32 delx = 0, dely = 0;
        for (i32 i = 1; i < n; ++i) {
            for (i32 j = 0; j < m; ++j) {
                if (arr[i][j] > mx) {
                    mx = arr[i][j];
                    delx = i;
                    dely = j;
                }
            }
        }
        for (i32 i = 0; i < n; ++i) {
            arr[i][dely] = -2e10;
        }
        for (i32 j = 0; j < m; ++j) {
            arr[delx][j] = -2e10;
        }
    }
    for (i32 i = 0; i < n; ++i) {
        bool flag = true;
        bool first = true;
        for (i32 j = 0; j < m; ++j)
            if (arr[i][j] != -2e10) {
                cout << (first ? "" : " ") << arr[i][j];
                first = false;
                flag = false;
            }
        if (!flag) cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
