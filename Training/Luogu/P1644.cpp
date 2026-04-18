#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n, m;
int ans = 0;
int a[MAXN][MAXN];
int dx[4] = {2, 1, -1, -2};
int dy[4] = {1, 2, 2, 1};


auto dfs(const int &x, const int &y) -> void {
    if (x == n && y == m) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > n || ny > m) continue;
        //cout << nx << "," << ny << endl;
        dfs(nx, ny);
    }
}

auto solve() -> void {
    cin >> n >> m;
    dfs(0, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
