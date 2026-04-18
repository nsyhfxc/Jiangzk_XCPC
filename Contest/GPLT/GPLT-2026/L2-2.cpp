#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    i32 n;
    cin >> n;

    vector<i32> arr(n + 1);
    i32 mx = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == mx) {
            cout << (flag ? " " : "") << i;
            flag = true;
        }
    }
    cout << endl;

    vector<pair<i32, int>> ord;
    ord.reserve(n);
    for (int i = 1; i <= n; i++) {
        ord.emplace_back(arr[i], i);
    }

    auto cmp = [](const pair<i32, int>& a, const pair<i32, int>& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    };
    sort(ord.begin(), ord.end(), cmp);

    int m;
    cin >> m;
    while (m--) {
        i32 x;
        cin >> x;

        pair<i32, int> key = {x, INT_MAX};
        auto it = upper_bound(ord.begin(), ord.end(), key, cmp);

        if (it == ord.end()) {
            cout << 0 << endl;
            //break;
        } else cout << it->second << endl;
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
