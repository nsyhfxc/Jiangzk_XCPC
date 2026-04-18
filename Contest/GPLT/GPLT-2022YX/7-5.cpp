#include <bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<i32, int> mp;
    for (int i = 0; i < n; ++i) {
        i32 x;
        cin >> x;
        mp[x]++;
    }
    const auto unique = mp.size();
    i32 dup = 0;
    for (auto &p: mp) {
        dup += p.second - 1;
    }

    i32 ans;
    if (k <= dup) ans = unique;
    else ans = max(0LL, static_cast<i32>(unique) - (k - dup));

    cout << ans << '\n';
    return 0;
}
