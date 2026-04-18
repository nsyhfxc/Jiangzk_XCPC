#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 400000 + 10; // 足够大
int fa[N], sz[N];
int n, m, p, q;
int find(const int &x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unionset(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        fa[find(x)] = find(y);
        sz[y] += sz[x];
    }
}

signed main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n >> m >> p >> q;
    int off = n;
    int tot = n + m;
    for (int i = 1; i <= tot; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        unionset(x, y);
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        x = -x + off;
        y = -y + off;
        unionset(x, y);
    }
    int rootM = find(1);
    int rootW = find(off + 1);
    int cntM = sz[rootM];
    int cntW = sz[rootW];
    cout << min(cntM, cntW) << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
