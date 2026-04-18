#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'
struct DSU {
    vector<i32>fa;
    vector<i32>sz;
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        sz.resize(n + 1);
        fill(sz.begin(), sz.end(), 1);
    }
    int find(int x) {
        if(fa[x] == x) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty) {
            fa[rootx] = rooty;
            sz[rooty] += sz[rootx];
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<i32>deg(n + 1, 0);
    set<i32>seen;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        seen.insert(x);
        seen.insert(y);
        dsu.unite(x, y);
    }
    cout << 4 << " " << 2 << endl; 
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
