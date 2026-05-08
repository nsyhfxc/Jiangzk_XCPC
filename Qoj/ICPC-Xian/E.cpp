#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<i64, i64> mp;
    for (int i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        mp[x]++;
    }
    i64 cnt = 0;
    for (const auto &[x,y]: mp) {
        if (y <= m) {
            cnt++;
        } else continue;
    }
    cout << cnt << endl;
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
