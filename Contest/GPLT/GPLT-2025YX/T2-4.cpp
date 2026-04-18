#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

struct DSU {
    vector<int> parent;
    vector<i32> sz;
    vector<i32> sum;

    DSU(int n, const vector<i32> &a) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        sum.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sum[i] = a[i - 1];//一开始没有分组，每个人都是一组，每个人拥有各自的数量的橘子
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;// A - B ,B - C , A - D
        return parent[i] = find(parent[i]);
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            i32 bonus = sz[root_u] * sz[root_v];
            parent[root_u] = root_v;
            sum[root_v] += sum[root_u] + bonus;
            sz[root_v] += sz[root_u];
        }
    }

    void add(int u, i32 x) {
        int root = find(u);
        sum[root] += x;
    }

    i32 query(int u) {
        return sum[find(u)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<i32> init(n);
    for (int i = 0; i < n; i++) {
        cin >> init[i];
    }
    DSU dsu(n, init);//调用构造函数，初始化 对象实例化 成员函数都是public
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else if (op == 2) {
            int u;
            i32 x;
            cin >> u >> x;
            dsu.add(u, x);
        } else if (op == 3) {
            int u;
            cin >> u;
            cout << dsu.query(u) << "\n";
        }
    }

    return 0;
}
