#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<i32, int> cnt;
    vector<i32> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    sort(arr.begin(), arr.end(), [&](i32 a, i32 b) {
        return abs(a) > abs(b);
    });
    vector<i32> res;
    for (const auto &x: arr) {
        if (cnt[x] > 0) {
            i32 s = x / 5;
            res.push_back(s);
            cnt[5 * s]--;
            cnt[2 * s]--;
            cnt[1 * s]--;
        }
    }
    sort(res.begin(), res.end(), greater<>());

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
