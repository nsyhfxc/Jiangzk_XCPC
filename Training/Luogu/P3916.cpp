#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
constexpr int N = 1e5 + 10;

int ans[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> edge[N];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge[v].push_back(u);
    }

    for (int i = n; i >= 1; i--) {
        if (ans[i]) continue;
        queue<int> q;
        q.push(i);
        ans[i] = i;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v: edge[u]) {
                if (!ans[v]) {
                    ans[v] = i;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (ans[i] ? ans[i] : i) << (i == n ? "" : " ");
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
