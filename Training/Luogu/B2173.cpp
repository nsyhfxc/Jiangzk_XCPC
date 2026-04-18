#include<bits/stdc++.h>
using namespace std;
int dp[1005];

int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 0; i < n; ++i) {
        int w, val, c;
        cin >> w >> val >> c;
        for (int k = 1; k <= c; ++k) {
            for (int j = v; j >= w; --j) {
                dp[j] = max(dp[j], dp[j - w] + val);
            }
        }
    }
    cout << dp[v] << endl;

    return 0;
}
