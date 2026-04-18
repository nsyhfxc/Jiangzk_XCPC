#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    int n;
    double m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        if (x < m) {
            cout << fixed << setprecision(1);
            cout << "On Sale! " << x << endl;
        }
    }
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
