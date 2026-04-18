#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int MAXN = 100005;

struct node {
    int lchild, rchild;
    int val;
    int rng;
    int size;
} tr[MAXN];

int root, idx;

void newnode(int &x, int v) {
    x = ++idx;
    tr[x].val = v;
    tr[x].rng = rand();
    tr[x].size = 1;
}

void pushup(int p) {
    tr[p].size = tr[tr[p].lchild].size + tr[tr[p].rchild].size + 1;
}

void split(int p, int v, int &x, int &y) {
    if (!p) {
        x = y = 0;
        return;
    }
    if (tr[p].val <= v) {
        x = p;
        split(tr[x].rchild, v, tr[x].rchild, y);
        pushup(x);
    } else {
        y = p;
        split(tr[y].lchild, v, x, tr[y].lchild);
        pushup(y);
    }
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (tr[x].rng < tr[y].rng) {
        tr[x].rchild = merge(tr[x].rchild, y);
        pushup(x);
        return x;
    } else {
        tr[y].lchild = merge(x, tr[y].lchild);
        pushup(y);
        return y;
    }
}

void insert(int v) {
    int x, y, z;
    split(root, v, x, y);
    newnode(z, v);
    root = merge(merge(x, z), y);
}

void del(int v) {
    int x, y, z;
    split(root, v, x, z);
    split(x, v - 1, x, y);
    y = merge(tr[y].lchild, tr[y].rchild);
    root = merge(merge(x, y), z);
}

int getrank(int v) {
    int x, y;
    split(root, v - 1, x, y);
    int ans = tr[x].size + 1;
    root = merge(x, y);
    return ans;
}

int getval(int root, int v) {
    if (v == tr[tr[root].lchild].size + 1)
        return tr[root].val;
    else if (v <= tr[tr[root].lchild].size)
        return getval(tr[root].lchild, v);
    else
        return getval(tr[root].rchild, v - tr[tr[root].lchild].size - 1);
}

int getpre(int v) {
    int x, y, s, ans;
    split(root, v - 1, x, y);
    s = tr[x].size;
    ans = getval(x, s);
    root = merge(x, y);
    return ans;
}

int getnxt(int v) {
    int x, y, ans;
    split(root, v, x, y);
    ans = getval(y, 1);
    root = merge(x, y);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, op, v;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> op >> v;
        if (op == 1)insert(v);
        else if (op == 2) del(v);
        else if (op == 3) cout << getrank(v) << endl;
        else if (op == 4) cout << getval(root, v) << endl;
        else if (op == 5) cout << getpre(v) << endl;
        else cout << getnxt(v) << endl;
    }
    return 0;
}
