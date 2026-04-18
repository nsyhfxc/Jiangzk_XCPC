#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
vector<vector<int> > a(1001, vector<int>(1001, 0));
vector<vector<int> > vis(1001, vector<int>(1001, 0));
vector<int> tot(1001);

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[j][a[i][j]]) {
                vis[j][a[i][j]] = 1;
                tot[a[i][j]]++;
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        cout << tot[i] << " ";
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
