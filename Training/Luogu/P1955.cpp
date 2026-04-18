#include<bits/stdc++.h>
using namespace std;
constexpr int N = 100005;
int t, n, cnt;
int a[N], b[N], e[N];
int p[N * 2];
unordered_map<int, int> mp;

int get(const int &x) {
    if (mp.count(x) == 0) mp[x] = ++cnt;
    return mp[x];
}

int find(const int &x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void solve() {
    cnt = 0;
    mp.clear();
    cin >> n;
    for (int i = 1; i <= n * 2; i++) p[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> e[i];
        a[i] = get(a[i]);
        b[i] = get(b[i]);
    }
    for (int i = 1; i <= n; i++)
        if (e[i] == 1) {
            int x = find(a[i]), y = find(b[i]);
            if (x != y) p[x] = y;
        }
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (e[i] == 0 && find(a[i]) == find(b[i])) {
            flag = false;
            break;
        }
    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}
