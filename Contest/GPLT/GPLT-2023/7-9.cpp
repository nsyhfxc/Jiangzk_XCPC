#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;

    vector<int> stA, stB; // A柱、B柱（栈顶在back）
    int cnt = 0, mx = 0; // 成品宝塔数、最高层数

    // 第1块先放A柱
    stA.emplace_back(a[0]);

    for (int i = 1; i < n; i++) {
        int c = a[i];

        if (c < stA.back()) {
            stA.emplace_back(c);
        } else {
            if (stB.empty() || c > stB.back()) {
                stB.emplace_back(c);
            } else {
                // A柱当前宝塔成为成品
                cnt++;
                mx = max(mx, (int) stA.size());
                stA.clear();

                // B柱上所有比c大的移到A柱
                while (!stB.empty() && stB.back() > c) {
                    stA.emplace_back(stB.back());
                    stB.pop_back();
                }
                // c放到A柱
                stA.emplace_back(c);
            }
        }
    }

    // 最后A柱作为一件成品
    if (!stA.empty()) {
        cnt++;
        mx = max(mx, (int) stA.size());
    }

    // B柱剩余彩虹圈再堆成一座宝塔
    if (!stB.empty()) {
        cnt++;
        mx = max(mx, (int) stB.size());
    }

    cout << cnt << ' ' << mx << endl;
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
