#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000010;
int n, m;
int x, y, z;
int fa[N];
int find(int x) {
    return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}
void unionset(int x,int y) {
    fa[find(x)] = find(y);
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    while (m--) {
        cin >> z >> x >> y;
        if (z == 1) {
            unionset(x, y);
        } else {
            cout << (find(x) == find(y)? 'Y' : 'N') << '\n';
        }
    }
    return 0;
}
