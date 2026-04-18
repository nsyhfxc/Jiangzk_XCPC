#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int l, n;
    cin >> l >> n;
    vector<int> init(n, l);
    map<vector<int>, i32> dp, ndp;
    dp[init] = 1;
    for (int r = 0; r < n; r++) {
        ndp.clear();
        for (auto &[st, cnt]: dp) {
            function<void(int, int, vector<int> &)> dfs = [&](int pos, int rem, vector<int> &ns) {
                if (pos == n) {
                    if (rem == 0) {
                        ndp[ns] += cnt;
                    }
                    return;
                }
                int up = min(rem, st[pos]);
                for (int v = 0; v <= up; v++) {
                    ns[pos] -= v;
                    dfs(pos + 1, rem - v, ns);
                    ns[pos] += v;
                }
            };

            vector<int> ns = st;
            dfs(0, l, ns);
        }

        dp.swap(ndp);
    }

    vector<int> zero(n, 0);
    cout << dp[zero] << endl;
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
