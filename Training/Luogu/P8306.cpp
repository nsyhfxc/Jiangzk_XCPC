#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 3e6 + 5;
int T, n, q;
int ch[N][65], cnt[N], idx;

auto getnum(const char &c) -> int {
    if (c >= 'A' && c <= 'Z') return c - 'A'; //0~25
    if (c >= 'a' && c <= 'z') return c - 'a' + 26; //26~51
    return c - '0' + 52;
}

auto insert(const string &s) -> void {
    int p = 0;
    for (const auto &c: s) {
        int i = getnum(c);
        if (!ch[p][i]) ch[p][i] = ++idx;
        p = ch[p][i];
        cnt[p]++;
    }
}

auto query(const string &s) -> int {
    int p = 0;
    for (const auto &c: s) {
        int i = getnum(c);
        if (!ch[p][i]) return 0;
        p = ch[p][i];
    }
    return cnt[p];
}

auto solve() -> void {
    cin >> n >> q;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s, insert(s);
    }
    for (int i = 1; i <= q; i++) {
        cin >> s, cout << query(s) << "\n";
    }

    for (int i = 0; i <= idx; i++) {
        for (int j = 0; j < 65; j++) {
            ch[i][j] = 0;
        }
    }

    for (int i = 0; i <= idx; i++) {
        cnt[i] = 0;
    }
    idx = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
