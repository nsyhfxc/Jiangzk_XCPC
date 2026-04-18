#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    auto diff = [&](char x, char y) -> int {
        return x != y;
    };
    auto get_tp = [&](int p) -> int {
        return (s[p] - '0') * 2 + (s[p + 1] - '0');
    };

    int base = 0;
    for (int i = 0; i + 1 < n; i++) base += diff(s[i], s[i + 1]);

    int gain[4][4];
    for (int t1 = 0; t1 < 4; t1++) {
        for (int t2 = 0; t2 < 4; t2++) {
            int a = (t1 >> 1) & 1, b = t1 & 1;
            int c = (t2 >> 1) & 1, d = t2 & 1;
            gain[t1][t2] = (a != c) + (b != d) - (a != b) - (c != d);
        }
    }

    int mx = 0;
    array<int, 4> seen{};
    seen.fill(0);
    for (int j = 0; j <= n - 2; j++) {
        if (j - 1 >= 0) seen[get_tp(j - 1)] = 1;
        int t2 = get_tp(j);
        for (int t1 = 0; t1 < 4; t1++) {
            if (seen[t1]) mx = max(mx, gain[t1][t2]);
        }
    }
    for (int r = 0; r <= n - 2; r++) {
        int delta = diff(s[0], s[r + 1]) - diff(s[r], s[r + 1]);
        mx = max(mx, delta);
    }
    for (int l = 1; l <= n - 1; l++) {
        int delta = diff(s[l - 1], s[n - 1]) - diff(s[l - 1], s[l]);
        mx = max(mx, delta);
    }

    cout << base + mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
