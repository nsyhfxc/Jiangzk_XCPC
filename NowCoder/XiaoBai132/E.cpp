#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<i64> ans(n + 1);
    for (int x = 1; x <= n; x++) {
        for (int l = 1; l <= x; l++) {
            for (int r = x; r <= n; r++) {
                bool lf = true, rg = true;
                for (int i = l; i <= x; i++) {
                    if (arr[i] > arr[x]) {
                        lf = false;
                    }
                }
                for (int i = x + 1; i <= r; i++) {
                    if (arr[i] > arr[x]) {
                        rg = false;
                    }
                }
                if (lf || rg) {
                    ans[x]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
