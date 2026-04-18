#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    i32 n;
    cin >> n;
    vector<i32> arr(n);
    i32 cnt = 0;
    i32 mx = -2e9;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt += arr[i];
        mx = max(mx, arr[i]);
    }
    if (cnt % 5 != 0 || (mx > cnt / 5)) {
        cout << "F" << endl;
        return;
    }

    cout << "T" << endl;
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
