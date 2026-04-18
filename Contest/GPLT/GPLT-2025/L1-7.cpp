#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
constexpr int N = 2e5;

i32 ksm(i32 a, i32 b) {
    i32 res = 1;
    while (b) {
        if (b & 1) res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    i32 n;
    cin >> n;
    vector<pair<i32, i32> > a;
    for (int i = 1; i < 31; i++) {
        i32 sum = 0, j = 1;
        while (sum <= n) {
            sum += ksm(j, i);
            if (sum == n) {
                a.emplace_back(i, j);
                break;
            }
            j++;
        }
    }
    if (a.empty()) {
        cout << "Impossible for " << n << ".";
        return;
    }
    const auto c = a.back().second;
    const auto b = a.back().first;
    for (int i = 1; i <= c; i++) {
        cout << (i == 1 ? "" : "+") << i << "^" << b;
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
}
