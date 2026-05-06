#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    vector<int> cnt(n + 2);
    i64 mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (a[i] <= n) cnt[a[i]]++;
    }

    vector<int> vis(n + 2);

    if (mx <= n) {
        cnt[mx]--;
        vis[mx] = 1;
    }

    int mex = 0;
    while (mex <= n && vis[mex]) mex++;

    i64 sum = mex;

    for (int i = 1; i < n; i++) {
        if (mex <= n && cnt[mex] > 0) {
            cnt[mex]--;
            vis[mex] = 1;
            while (mex <= n && vis[mex]) mex++;
        }
        sum += mex;
    }

    const i64 ans = sum + mx * n;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
