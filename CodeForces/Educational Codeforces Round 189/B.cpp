#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    string s;
    cin >> s;
    auto n = s.size();
    vector<int> mis(n);
    for (int i = 0; i < n; i++) {
        char c = (i % 2 == 0 ? 'a' : 'b');
        mis[i] = (s[i] != c);
    }
    auto calc = [&](int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mis[i] == x && (i == 0 || mis[i - 1] != x)) {
                cnt++;
            }
        }
        return cnt;
    };
    if (calc(0) <= 1 || calc(1) <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
