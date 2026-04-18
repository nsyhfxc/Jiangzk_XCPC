#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        string s;
        cin >> s;
        int res = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'n') {
                res += pow(2, n - 1 - i);
            }
        }
        cout << res << endl;
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
