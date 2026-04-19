#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, k;
int fa[N];
int x, y;
int find(int x) {
    return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

void unionset(int x,int y) {
    fa[find(x)] = find(y);
}

signed main() {
    unordered_map<string,int> mp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        x = mp[s1];
        y = mp[s2];
        unionset(x, y);
    }
    cin >> k;
    while (k--) {
        string s1, s2;
        cin >> s1 >> s2;
        x = mp[s1];
        y = mp[s2];
        cout << (find(x) == find(y) ? "Yes." : "No.") << endl;
    }
    return 0;
}
