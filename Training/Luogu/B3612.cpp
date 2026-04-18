#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    s[1] = a[1];
    for (int i = 2; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
