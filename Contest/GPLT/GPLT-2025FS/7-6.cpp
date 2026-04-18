#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa;
    vector<int> sz;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0); // 0 1 2 3 ……
        sz.assign(n + 1, 1);
    }

    int find(int x) {
        if (fa[x] == x) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }

    void unite(int x,int y) {
        //找的是x的祖先，y的祖先
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            fa[rootx] = rooty;
            sz[rooty] += sz[rootx];//把x合并给了y
        }
    }

    bool same(int x,int y) {
        return find(x) == find(y);//x 和 y 是同一个集合 ,祖先相同
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        dsu.unite(u,v);
    }
    int q;
    cin >> q;
    while (q--) {
        int u,v;
        cin >> u >> v;
        cout << (dsu.same(u,v) ? "Yes" : "No") << endl;
    }
}
