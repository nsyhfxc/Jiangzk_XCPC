#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
i32 dp[1000006][4];
int main() {
    string s;
    cin >> s;
    const int n = s.length();


    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i - 1][j - 1];
            for (int k = 1; k <= j; k++) {
                if (i - 1 - k >= 0 && s[i - 1] == s[i - 1 - k]) {
                    dp[i][j] -= dp[i - 1 - k][j - k];
                    break;
                }
            }
        }
    }
    cout << dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] << endl;
    return 0;
}
