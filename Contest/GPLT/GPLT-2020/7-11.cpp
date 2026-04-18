#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct Node {
    int u, l, r;
};

void solve() {
    int n;
    cin >> n;

    vector<int> post(n + 1), sz(n + 2, 0), ans;
    for (int i = 1; i <= n; i++) cin >> post[i];

    for (int i = n; i >= 1; i--) {
        sz[i] = 1;
        if ((i << 1) <= n) sz[i] += sz[i << 1];
        if ((i << 1 | 1) <= n) sz[i] += sz[i << 1 | 1];
    }

    queue<Node> q;
    q.push({1, 1, n});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int u = cur.u, l = cur.l, r = cur.r;
        ans.push_back(post[r]);

        int lc = u << 1, rc = u << 1 | 1;
        int ls = (lc <= n ? sz[lc] : 0);

        if (lc <= n) {
            q.push({lc, l, l + ls - 1});
        }
        if (rc <= n) {
            q.push({rc, l + ls, r - 1});
        }
    }

    for (int i = 0; i < (int)ans.size(); i++) {
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