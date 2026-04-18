#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    string s, key = "chi1 huo3 guo1";
    i32 cnt = 0, first = -1, sum = 0;

    auto check = [&](const string &t) {
        return t.find(key) != string::npos;
    };

    while (getline(cin, s)) {
        if (s == ".") break;
        cnt++;
        if (check(s)) {
            sum++;
            if (first == -1) first = cnt;
        }
    }

    cout << cnt << endl;
    if (sum == 0) {
        cout << "-_-#" << endl;
    } else {
        cout << first << ' ' << sum << endl;
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
