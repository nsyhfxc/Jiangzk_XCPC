#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    string line;
    getline(cin, line);
    auto check = [&](const string &str)-> bool {
        int l = 0, r = (int) str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++, r--;
        }
        return true;
    };
    int mx = 0;
    for (int i = 0; i < line.size(); i++) {
        string temp;
        for (int j = i; j < line.size(); j++) {
            temp += line[j];
            if (check(temp)) {
                mx = max(mx, (int) temp.size());
            }
        }
    }
    cout << mx << endl;
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
