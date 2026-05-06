#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    i64 sum = 0;
    i64 ans = 0;
    for (int i = n; i >= 1; i--) {
        sum += arr[i];
        if (sum > 0) {
            ans++;
        } else sum = 0;
    }
    cout << ans << endl;
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
