#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n';

void solve() {
    int q;
    cin >> q;
    list<char> lnode;
    while (q--) {
        char op;
        int i;
        cin >> op >> i;
        auto it = lnode.begin();
        int n = lnode.size();
        if (i <= 10) {
            it = lnode.begin();
            int steps = (op == 'I') ? i : i - 1;
            for (int k = 0; k < steps; ++k) if (it != lnode.end()) ++it;
        } else {
            it = lnode.end();
            int n = lnode.size();
            int steps = (op == 'I') ? (n - i) : (n - i + 1);
            for (int k = 0; k < steps; ++k) if (it != lnode.begin()) --it;
        }
        if (op == 'I') {
            char c;
            cin >> c;
            lnode.insert(it, c);
        } else if (op == 'D') {
            if (it != lnode.end()) {
                lnode.erase(it);
            }
        }
    }

    for (const auto &c: lnode) cout << c;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
