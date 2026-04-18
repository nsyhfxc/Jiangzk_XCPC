#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, m, q;
    cin >> n >> m;

    vector<set<int> > st(m + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int x;
            cin >> x;
            st[x].insert(i);
        }
    }

    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for (auto &x: st[a]) {
            if (st[b].count(x)) {
                ++cnt;
            }
        }
        cout << cnt << endl;
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
