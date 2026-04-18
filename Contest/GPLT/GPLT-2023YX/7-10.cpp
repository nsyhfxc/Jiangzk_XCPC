#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'
constexpr int mod = 114514;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int num = 0;
    for (int i = 1; i <= n; i++) {
        int opt;
        u32 a;
        cin >> opt >> a;
        if (opt == 0) {
            num = (num + a) % mod;
        } else if (opt == 1) {
            num = (num - a) % mod;
        } else if (opt == 2) {
            num = num % mod * (a % mod) % mod;
        }
    }
    cout << num << endl;
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
