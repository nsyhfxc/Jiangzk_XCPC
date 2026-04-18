#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, m, k;
    string x;
    cin >> n >> x >> m >> k;
    if (k == n) {
        cout << "mei you mai " << x << " de" << endl;
    } else if (k == m) {
        cout << "kan dao le mai " << x << " de" << endl;
    } else cout << "wang le zhao mai " << x << " de" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
