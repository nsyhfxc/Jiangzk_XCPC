#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    vector<u64> arr;
    for (int i = 0; i < 63; i++) {
        for (int j = i; j < 63; j++) {
            arr.push_back((1ULL << i) + (1ULL << j));
        }
    }
    sort(arr.begin(), arr.end());
    while (t--) {
        u64 l, r;
        cin >> l >> r;

        auto left = lower_bound(arr.begin(), arr.end(), l);
        auto right = upper_bound(arr.begin(), arr.end(), r);

        cout << right - left << endl;
    }
}
