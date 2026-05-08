#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n != m || n == 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << 2 << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (i + j) % n + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
