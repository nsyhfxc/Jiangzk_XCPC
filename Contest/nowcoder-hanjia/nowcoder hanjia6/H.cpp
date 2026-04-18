#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> dp(2048), temp(2048);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        fill(temp.begin(), temp.end(), 0);
        for (int x = 0; x < 2048; x++) {
            if (!dp[x]) continue;
            int x1 = max(0, x - a[i]);
            int x2 = x ^ b[i];
            temp[x1] = 1;
            temp[x2] = 1;
        }
        swap(dp, temp);
    }
    for (int x = 2047; x >= 0; x--) {
        if (dp[x]) {
            cout << x << '\n';
            break;
        }
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
}
