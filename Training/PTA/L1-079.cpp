#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> db;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    int mn = 2e9,mns = 2e9;
    int mx = -2e9,mxs = 2e9;
    for (const auto &[x,y]: db) {
        if (x > mx) {
            mx = x;
            mxs = y;
        }
        if (x < mn) {
            mn = x;
            mns = y;
        }
    }
    cout << mn << " " << mns << endl;
    cout << mx << " " << mxs << endl;
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
