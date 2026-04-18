#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(25, 0);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        for (int k = 0; k < 25; k++) {
            if ((val >> k) & 1) cnt[k]++;
        }
    }

    i32 ans = 0;
    for (int i = 0; i < n; i++) {
        i32 cur = 0;
        for (int k = 0; k < 25; k++) {
            if (cnt[k] > 0) {
                cur |= (1LL << k);
                cnt[k]--;
            }
        }
        ans = (ans + cur * cur) % mod;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
