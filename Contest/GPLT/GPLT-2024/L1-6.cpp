#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<double> arr(n + 1);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    double sum = 0;
    int x, y;
    while (cin >> x >> y, x) {
        cnt[x] += y;
        sum += arr[x] * y;
    }

    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << endl;
    }
    cout << fixed << setprecision(2) << sum << endl;
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
