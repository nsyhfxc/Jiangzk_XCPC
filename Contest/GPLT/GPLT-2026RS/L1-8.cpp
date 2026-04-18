#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    while (n--) {
        int op;
        cin >> op;

        if (op == 1) {
            string s1;
            cin >> s1;
            size_t pos = s.find(s1);
            cout << (pos == string::npos ? -1 : (int) pos) << endl;
        } else if (op == 2) {
            string s2, s3;
            cin >> s2 >> s3;
            size_t pos = s.find(s2);
            if (pos != string::npos) {
                s = s.substr(0, pos) + s3 + s.substr(pos + s2.size());
            }
            cout << s << endl;
        } else if (op == 3) {
            char c1, c2;
            string s4;
            cin >> c1 >> c2 >> s4;

            string temp;
            temp.reserve(s.size() * 2); // 可选优化

            bool changed = false;
            for (size_t i = 0; i < s.size(); i++) {
                temp += s[i];
                if (i + 1 < s.size() && s[i] == c1 && s[i + 1] == c2) {
                    temp += s4;
                    changed = true;
                }
            }

            if (changed) s = temp;
            cout << s << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
