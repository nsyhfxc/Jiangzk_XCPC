#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

struct Circle {
    i64 x, y, r;
};

void solve() {
    int n;
    cin >> n;
    vector<Circle> c(n);
    for (auto &[x, y, r]: c) {
        cin >> x >> y >> r;
    }
    int q;
    cin >> q;
    auto check = [&](const Circle &cir, i64 x, i64 y) {
        i64 dx = x - cir.x;
        i64 dy = y - cir.y;
        return dx * dx + dy * dy <= cir.r * cir.r;
    };
    while (q--) {
        i64 x, y;
        cin >> x >> y;
        int color = 0;
        for (const auto &cir: c) {
            if (check(cir, x, y)) {
                color ^= 1;
            }
        }
        cout << (color ? "Yes" : "No") << endl;
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

    return 0;
}
