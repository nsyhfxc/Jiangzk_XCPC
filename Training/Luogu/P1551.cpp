#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 100010;
int n, m, p;
int x, y;
int fa[N];
int find(const int &x) {
    return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

void unionset(const int &x, const int &y) {
    fa[find(x)] = find(y);
}

signed main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        unionset(x, y);
    }
    for (int i = 1; i <= p; i++) {
        cin >> x >> y;
        cout << (find(x) == find(y) ? "Yes" : "No") << endl;
    }
    return 0;
}
