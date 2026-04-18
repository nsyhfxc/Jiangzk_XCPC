#include<bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1|1
#define N 500005
#define int long long
int m, n, w[N];

struct node {
    int l, r, sum, add;
} tr[N * 4];


void build(int p, int l, int r) {
    tr[p] = {l, r, w[l], 0};
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(lc, l, m);
    build(rc, m + 1, r);
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushup(int p) {
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p) {
    if (tr[p].add) {
        tr[lc].sum += tr[p].add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum += tr[p].add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[p].add = 0;
    }
}

void update(int p, int x, int y, int k) {
    if (x <= tr[p].l && tr[p].r <= y) {
        tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
        tr[p].add += k;
        return;
    }
    int m = (tr[p].l + tr[p].r) >> 1;
    pushdown(p);
    if (x <= m) {
        update(lc, x, y, k);
    }
    if (y > m) {
        update(rc, x, y, k);
    }
    pushup(p);
}

int query(int p, int x, int y) {
    if (x <= tr[p].l && tr[p].r <= y) {
        return tr[p].sum;
    }
    int m = (tr[p].l + tr[p].r) >> 1;
    int sum = 0;
    pushdown(p);
    if (x <= m) sum += query(lc, x, y);
    if (y > m) sum += query(rc, x, y);
    return sum;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    build(1, 1, n);
    while (m--) {
        int op, x, y, k;
        cin >> op;
        switch (op) {
            case 1:
                cin >> x >> y >> k;
                update(1, x, y, k);
                break;
            case 2:
                cin >> x >> y;
                cout << query(1, x, y) << endl;
            default:
                break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
