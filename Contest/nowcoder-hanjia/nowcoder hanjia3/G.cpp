#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using i64 = unsigned long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    i64 left = 0, right = 0;
    vector<i64> al(n), ar(m);
    for (auto &x: al) {
        cin >> x;
        left += x;
    }
    for (auto &x: ar) {
        cin >> x;
        right += x;
    }

    if (left == right) {
        cout << 1 << endl;
    } else {
        if (left < right) {
            swap(left, right);
            swap(al, ar);
        }
        sort(al.rbegin(), al.rend());
        int cnt = 0;
        for (const auto &x: al) {
            left -= x;
            cnt++;
            if (left <= right) break;
        }
        cout << cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
