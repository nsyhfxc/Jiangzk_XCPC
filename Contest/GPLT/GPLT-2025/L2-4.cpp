#include <bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using namespace std;

void solve() {
    i64 n, a, b;
    cin >> n >> a >> b;
    vector<i64> p10(n + 1, 1);
    for (int i = 1; i <= n; i++) p10[i] = p10[i - 1] * 10;
    bool found = false;
    function<void(int, i64)> dfs = [&](int pos, i64 cur) {
        // pos: 当前要填的位次
        // cur: 已构造的前缀值
        if (pos > n) {
            // 已构造完 n 位
            if (cur >= a && cur <= b) {
                cout << cur << endl;
                found = true;
            }
            return;
        }
        int start = (pos == 1 ? 1 : 0);
        for (int d = start; d <= 9; d++) {
            i64 next = cur * 10 + d;
            // 前缀可整除条件
            if (next % pos != 0) continue;
            // 剪枝：估计补全后可达到的最小/最大值是否与 [a,b] 相交
            int rem = n - pos;
            i64 mn = next * p10[rem];
            i64 mx = mn + p10[rem] - 1;
            if (mx < a || mn > b) continue;
            dfs(pos + 1, next);
        }
    };
    dfs(1, 0);
    if (!found) {
        cout << "No Solution" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
