#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;

struct DSU {
    vector<int> fa;
    vector<int> sz;

    explicit DSU(int n) {
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] == x) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }

    void unionset(int x,int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            fa[rootx] = rooty;
            sz[rooty] += sz[rootx];
        }
    }
};


signed main() {
    int n, m, k;
    int x, y;
    unordered_map<string,int> mp;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
    }
    for (int i = 1; i <= m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        x = mp[s1];
        y = mp[s2];
        dsu.unionset(x, y);
    }
    cin >> k;
    while (k--) {
        string s1, s2;
        cin >> s1 >> s2;
        x = mp[s1];
        y = mp[s2];
        cout << (dsu.find(x) == dsu.find(y) ? "Yes." : "No.") << endl;
    }
    return 0;
}
