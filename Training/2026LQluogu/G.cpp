#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int INF = 1e9;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    int n = (y + 1) * (z + 1);
    vector<array<int, 3> > cur(n), nxt(n);
    auto id = [&](int j, int k) {
        return j * (z + 1) + k;
    };

    auto clear_dp = [&](vector<array<int, 3> > &dp) {
        for (auto &v: dp) {
            v = {-INF, -INF, -INF};
        }
    };

    auto relax = [&](int &a, int b) {
        if (a < b) a = b;
    };

    clear_dp(cur);
    cur[id(0, 0)][1] = 0;

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            for (int k = 0; k <= z; k++) {
                int pos = id(j, k);

                for (int e = 0; e <= 2; e++) {
                    if (cur[pos][e] < 0) continue;

                    // 复习第二科，效率不变
                    if (j < y) {
                        relax(cur[id(j + 1, k)][e], cur[pos][e] + e);
                    }

                    // 复习第三科，效率 +1，最多为 2
                    if (k < z) {
                        int ne = min(2, e + 1);
                        relax(cur[id(j, k + 1)][ne], cur[pos][e] + e);
                    }
                }
            }
        }

        if (i == x) break;

        clear_dp(nxt);

        for (int j = 0; j <= y; j++) {
            for (int k = 0; k <= z; k++) {
                int pos = id(j, k);

                for (int e = 0; e <= 2; e++) {
                    if (cur[pos][e] < 0) continue;

                    // 复习第一科，效率 -1，最少为 0
                    int ne = max(0, e - 1);
                    relax(nxt[pos][ne], cur[pos][e] + e);
                }
            }
        }

        swap(cur, nxt);
    }

    int ans = 0;
    for (int e = 0; e <= 2; e++) {
        ans = max(ans, cur[id(y, z)][e]);
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

    return 0;
}
