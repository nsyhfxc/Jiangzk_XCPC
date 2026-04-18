#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int minnum = 2e9;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minnum = min(minnum, x);
    }
    int l = 0, r = 0;
    for (const auto &x: arr) {
        if (x > minnum) l++;
        else r++;
    }
    auto func = [&](const int &x)-> i32 {
        if (x == 0 || x == 1) return 1;
        vector<i32> dp(x + 1, 1);
        for (int i = 2; i <= x; i++) {
            dp[i] = dp[i - 1] * i % MOD;
        }
        return dp[x] % MOD;
    };
    //cout << "l: " << l << " , r: " << r << endl;
    cout << func(l) % MOD * func(r) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
