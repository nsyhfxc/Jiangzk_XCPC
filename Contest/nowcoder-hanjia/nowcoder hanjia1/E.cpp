#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, k;
    cin >> n >> k;
    queue<int> que;
    que.push(k);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        que.push(x);
    }
    // 5 1 2 3 3 2 1
    // 1 2 3 3 2 1 5
    n++;
    int res = -2e9;
    while (n--) {
        res = max(res, que.front() + que.back());
        int x = que.front();
        que.pop();
        que.push(x);
    }
    cout << res << endl;
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
