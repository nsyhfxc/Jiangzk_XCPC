#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int a, b;
    cin >> a >> b;
    const int n = a + b;
    vector<i32> dp(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }
    cout << dp[n] << endl;
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