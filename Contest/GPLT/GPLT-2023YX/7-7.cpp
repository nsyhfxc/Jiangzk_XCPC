#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt0 = 0;
        int cnt1 = 0;
        for (int j = i; j <= n; j++) {
            if (arr[j] == 0) {
                cnt0++;
            } else cnt1++;
            if (cnt0 == cnt1) {
                res = max(res, j - i + 1);
            }
        }
    }
    cout << res << endl;
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
