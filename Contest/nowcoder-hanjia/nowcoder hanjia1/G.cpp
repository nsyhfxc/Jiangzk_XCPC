#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;


void solve() {
    i32 l, r;
    cin >> l >> r;
    auto folded = [&](const i32 &x)-> i32 {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return stoll(s);
    };

    const string rs = to_string(r);
    i32 ans = folded(r);
    ans = max(ans, folded(l));
    for (int i = 0; i < rs.size(); ++i) {
        for (int d = 0; d < (rs[i] - '0'); ++d) {
            if (i == 0 && d == 0 && rs.size() > 1) continue;
            string tmp = rs;
            tmp[i] = static_cast<char>(d + '0');
            for (int j = i + 1; j < rs.size(); ++j) tmp[j] = '9';
            i32 val = stoll(tmp);
            if (val >= l) ans = max(ans, folded(val));
        }
    }
    i32 p10 = 9;
    for (int i = 0; i < 15; ++i) {
        if (p10 >= l && p10 <= r) ans = max(ans, p10);
        p10 = p10 * 10 + 9;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
