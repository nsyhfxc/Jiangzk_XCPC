#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 100001;
int ans = 0, n, d;
vector<int> edge[N];
void dfs(int x, int p, int dis) {
    if (dis >= d) {
        return;
    }
    for (int i = 0; i < edge[x].size(); i++) {
        if (edge[x][i] == p) {
            continue;
        }
        dfs(edge[x][i], x, dis + 1);
        ans++;
    }
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
