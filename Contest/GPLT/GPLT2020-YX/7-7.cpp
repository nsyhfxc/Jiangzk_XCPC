#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'
constexpr int mod = 19260817;

int main() {
    int n;
    cin >> n;
    vector<i32> dp(n + 1, 0);
    dp[1] = 2, dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] % mod * 2 + dp[i - 2] % mod * 3 + 5) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}
