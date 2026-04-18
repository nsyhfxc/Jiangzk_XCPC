#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353
using db = long double;

struct Ruler {
    db x, y, res;

    bool operator<(const Ruler &other) const {
        return res < other.res;
    }
};

void solve() {
    db n;
    int w;
    cin >> n >> w;
    priority_queue<Ruler> pq;
    db ans = 0;
    auto polish = [&](const db x, const db y)-> db {
        if (y <= 0) return 0;
        return sqrt(1LL * x * x + 1LL * y * y) -
               sqrt(1LL * x * x + 1LL * (y - 1) * (y - 1));
    };
    for (int i = 0; i < n; ++i) {
        db x, y;
        cin >> x >> y;
        ans += sqrt(x * x + y * y);
        if (y > 0) pq.push({x, y, polish(x, y)});
    }
    while (w-- && !pq.empty()) {
        Ruler tp = pq.top();
        pq.pop();
        ans -= tp.res;
        tp.y--;
        if (tp.y > 0) {
            tp.res = polish(tp.x, tp.y);
            pq.push(tp);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
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
