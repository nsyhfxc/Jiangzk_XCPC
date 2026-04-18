#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<i32> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<int> path(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        cin >> path[i];
        deg[path[i]]++;
    }
    queue<int> que;
    vector<i32> f(n + 1, 0); //dp
    vector<i32> m(n + 1, 2e18); //f最小值
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            f[i] = arr[i];
            que.push(i);
        }
    }

    while (!que.empty()) {
        const auto u = que.front();
        que.pop();
        if (u == 1) continue;
        int parent = path[u];
        m[parent] = min(m[parent], f[u]);
        deg[parent]--;
        if (deg[parent] == 0) {
            if (parent != 1) {
                f[parent] = min(m[parent], (m[parent] + arr[parent]) / 2);
            }
            que.push(parent);
        }
    }
    cout << arr[1] + m[1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();


    return 0;
}
