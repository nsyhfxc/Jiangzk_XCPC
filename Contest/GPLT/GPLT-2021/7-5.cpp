#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    unordered_map<i32, i32> db;
    for (int i = 0; i < 24; i++) {
        int x;
        cin >> x;
        db[i] = x;
    }
    int m;
    while (cin >> m) {
        if (m > 23 || m < 0) {
            break;
        }
        if (db[m] > 50) {
            cout << db[m] << " Yes" << endl;
        }else cout << db[m] << " No" << endl;
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
