#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    string str;
    cin >> str;
    stack<string> stk;
    for (const auto &c: str) {
        if (c == '(') {
            stk.push("");
        } else if (c == ')') {
            cout << stk.top() << endl;
            stk.pop();
        } else {
            stk.top().push_back(c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
