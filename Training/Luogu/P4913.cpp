#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int L[N], R[N];
int n;
int dfs(int u) {
    if (u == 0) return 0;
    int lh = dfs(L[u]);
    int rh = dfs(R[u]);
    return max(lh, rh) + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];
    cout << dfs(1) << "\n";
    return 0;
}
