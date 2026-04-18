#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    string str;
    getline(cin, str);
    bool Cap = false;
    string res = "";
    auto check = [&](const char &ch) {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    };
    for (const auto &c: str) {
        if (check(c)) {
            if (c >= 'a' && c <= 'z') {
                if (Cap) {
                    char temp = toupper(c);
                    res += temp;
                } else res += c;
            } else res += c;
        } else if (c == '<') {
            if (!res.empty()) {
                res.pop_back();
            }
        } else if (c == '^') {
            Cap ^= 1;
        } else if (c == '@') {
            if (res.size() >= 2) {
                char c1 = res.back();
                res.pop_back();
                char c2 = res.back();
                res.pop_back();
                res = res + c1 + c2;
            }
        } else if (c == '#') {
            if (!res.empty()) {
                res += res.back();
            }
        } else if (c == '!') {
            res = "";
        }
    }
    cout << res << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }
    return 0;
}
