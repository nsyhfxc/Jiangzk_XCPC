#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

const int N = 1e5 + 10;
vector<int> grid[N];
vector<int> ans;
int n, rt, mx, d[N];

void solve() {
    cin >> n;
    for (int v = 1, u; v <= n; v++) {
        cin >> u;
        if (!u) rt = v;
        else {
            grid[u].emplace_back(v);
            d[u]++;
        }
        mx = max(mx, d[u]);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (d[i] && d[i] != mx) {
            flag = false;
            break;
        }
    }
    cout << mx << ' ' << (flag ? "yes" : "no") << endl;

    auto dfs = [&](auto &&self, int u) -> void {
        ans.emplace_back(u);
        for (auto &v: grid[u]) {
            self(self, v);
        }
    };
    dfs(dfs, rt);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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
