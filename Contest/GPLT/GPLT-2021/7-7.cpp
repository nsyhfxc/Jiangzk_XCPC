#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    int mx = -2e9, mn = 2e9;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        if (x > mx) mx = x;
        if (x < mn) mn = x;
    }
    cout << mn << " " << mp[mn] << endl;
    cout << mx << " " << mp[mx] << endl;
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
