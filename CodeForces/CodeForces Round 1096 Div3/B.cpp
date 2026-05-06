#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    int cnt1 = 0, cnt2 = 0;
    for (const auto &c: s) {
        if (c == '(') {
            cnt1++;
        } else cnt2++;
    }
    if (cnt1 != cnt2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
