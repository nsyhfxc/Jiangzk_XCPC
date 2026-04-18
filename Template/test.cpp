#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
constexpr int N = 1e9 + 7;
constexpr int mod = 998244353;

void solve() {
    cout << [&]()-> string {
        return "HUE GPLT WIN!!!";
    }() << endl;
    function<i32(i32)> func = [&](i32 n)-> i32 {
        if (n == 1 || n == 0) {
            return 1;
        }
        return func(n - 1) + func(n - 2);
    };
    cout << func(10) << endl;
    vector<pair<string, string> > arr(1);
    for (auto &[x, y]: arr) {
        x = "HUE GPLT";
        y = "WIN!!!";
    }
    for (const auto &[x, y]: arr) {
        cout << x << " " << y << endl;
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
