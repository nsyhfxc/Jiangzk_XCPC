#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > g(n);
    vector<int> indeg(n, 0);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int v;
            cin >> v;
            g[i].emplace_back(v);
            indeg[v]++;
        }
    }

    int rt = -1;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            rt = i;
            break;
        }
    }

    vector<int> dp(n, 0);
    function<void(int)> dfs = [&](int u) {
        dp[u] = 1;
        for (int v: g[u]) {
            dfs(v);
            dp[u] = max(dp[u], dp[v] + 1);
        }
    };

    dfs(rt);

    vector<int> ans;
    int u = rt;
    while (true) {
        ans.emplace_back(u);
        int nxt = -1, mx = 0;
        for (int v: g[u]) {
            if (dp[v] > mx || (dp[v] == mx && (nxt == -1 || v < nxt))) {
                mx = dp[v];
                nxt = v;
            }
        }
        if (nxt == -1) break;
        u = nxt;
    }

    cout << dp[rt] << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
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
