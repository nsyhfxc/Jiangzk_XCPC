#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    cout << s.front();
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == ']') {
            if (s[i - 1] != '[') {
                cout << "[]";
            }else {
                cout << "]";
            }
        }
        if (s[i] == ')') {
            if (s[i - 1] != '(') {
                cout << "()";
            }else {
                cout << ")";
            }
        }
        if (s[i] == '(' || s[i] == '[') {
            cout << s[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
