#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, m, k;
    cin >> n >> m;
    vector<vector<int> > arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k;
        arr[i].emplace_back(0);
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            arr[i].emplace_back(x);
        }
    }
    vector<int> sv(m);
    int cur = 1;
    for (int i = 0; i < m; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 0) {
            cur = arr[cur][x];
        } else if (op == 1) {
            sv[x] = cur;
            cout << cur << endl;
        } else {
            cur = sv[x];
        }
    }
    cout << cur << endl;
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
