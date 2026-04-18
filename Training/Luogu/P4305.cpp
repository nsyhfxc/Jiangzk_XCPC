#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    unordered_map<int,int> s;
    int it = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!s.count(x)) {
            s[it] = x;
            it++;
        }
    }
    for (auto x : s) {
        cout << x.second << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}