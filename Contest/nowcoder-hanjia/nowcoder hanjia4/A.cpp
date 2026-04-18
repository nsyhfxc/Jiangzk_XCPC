#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

void solve() {
    int n;
    cin >> n;
    vector<i32> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    i32 sum = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (v[j] <= v[i]) {
                cnt++;
            }
        }
        if (cnt * 10 >= (n - 1) * 8) {
            sum += v[i];
        }
    }

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
