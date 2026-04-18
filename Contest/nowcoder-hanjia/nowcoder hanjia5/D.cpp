#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
constexpr int MOD = 1e9 + 7;

struct Half {
    i32 w;
    i32 cnt;

    bool operator>(const Half &a) const {
        return w > a.w;
    }
};

void solve() {
    int n;
    cin >> n;
    priority_queue<Half, vector<Half>, greater<> > pq;
    for (int i = 0; i < n; ++i) {
        i32 c, w;
        cin >> c >> w;
        pq.push({w, c});
    }
    i32 cnt = 0;
    while (!pq.empty()) {
        Half temp = pq.top();
        pq.pop();
        if (temp.cnt > 1) {
            i32 pirs = temp.cnt / 2;
            i32 nw = temp.w * 2;
            cnt = (cnt + (pirs % mod) * (nw % mod)) % mod;
            pq.push({nw, pirs});
            temp.cnt %= 2;
        }

        if (temp.cnt == 1) {
            if (pq.empty()) break;
            Half rem = pq.top();
            pq.pop();
            i32 pirs = temp.w + rem.w;
            cnt = (cnt + (pirs % mod)) % mod;
            pq.push({pirs, 1});
            if (rem.cnt > 1) {
                pq.push({rem.w, rem.cnt - 1});
            }
        }
    }

    cout << cnt << endl;
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
