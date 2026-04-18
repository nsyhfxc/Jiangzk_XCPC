#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int l, n;
    cin >> l >> n;
    unordered_map<int, char> db;
    for (int i = 0; i < 26; ++i) {
        db[i] = static_cast<char>('a' + i);
    }

    i32 num = pow(26, l) - n;
    string res = "";
    for (int i = 0; i < l; ++i) {
        res += db[num % 26];
        num /= 26;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
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
