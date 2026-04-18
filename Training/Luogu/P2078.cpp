#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa; //父节点
    vector<int> sz; // 当前节点的根节点下朋友圈的总人数

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0); // 递增填充
        sz.assign(n + 1, 1); //初始化为n+1个1
    }

    int find(int x) {
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
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    int off = n; //女生编号是负的，需要引入数组下标偏移量，男生保持1到n不变，女生的先取负，再加上男生的编号总数，就保证男生和女生的编号都是正的，且不重叠
    int tot = n + m; //男生和女生的总数
    DSU dsu(tot);
    for (int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unionset(x, y);//先合并男生
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        x = -x + off;
        y = -y + off;
        dsu.unionset(x, y);//再合并女生
    }
    int rootM = dsu.find(1);// 小明的根节点
    int rootW = dsu.find(off + 1); //小红的根节点
    int cntM = dsu.sz[rootM];// 与小明认识的男生数
    int cntW = dsu.sz[rootW]; //与小红认识的女生数
    cout << min(cntM, cntW) << endl;//总数，看看是想找对象的男生多，还是想找对象的女生多
    return 0;
}
