#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        const int start = max(cur, l);
        if (start <= r) {
            cout << start << " ";
            cur = start + 1;
        } else {
            cout << 0 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
