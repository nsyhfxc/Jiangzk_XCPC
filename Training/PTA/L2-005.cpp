#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    vector<set<int> > s(n + 1);
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            s[i].insert(x);
        }
    }
    cin >> k;
    cout << fixed << setprecision(2);
    while (k--) {
        int a, b;
        cin >> a >> b;
        auto &s1 = s[a];
        auto &s2 = s[b];
        if (s1.size() > s2.size()) {
            swap(s1, s2);
        }
        int Nc = 0;
        for (const auto &x: s1) {
            if (s2.count(x)) Nc++;
        }
        const int Nt = static_cast<int>(s[a].size() + s[b].size()) - Nc;
        const double sim = 100.0 * static_cast<double>(Nc) / static_cast<double>(Nt);
        cout << sim << "%\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
