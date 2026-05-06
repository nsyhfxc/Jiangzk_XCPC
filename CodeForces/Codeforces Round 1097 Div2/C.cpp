#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int bal = 0;
    int cnt = 0;
    bool ok = true;

    for (int i = 0; i < n; i++) {
        if (a[i] == '(' && b[i] == '(') {
            bal++;
        } else if (a[i] == ')' && b[i] == ')') {
            bal--;
        } else {
            cnt++;
        }
        if (bal < 0) ok = false;
        if (bal == 0) {
            if (cnt & 1) ok = false;
            cnt = 0;
        }
    }

    if (bal != 0) ok = false;

    cout << (ok ? "YES" : "NO") << endl;
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
