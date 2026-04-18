#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    stack<i32> s1;
    stack<char> s2;

    for (int i = 0; i < n; i++) {
        i32 x;
        cin >> x;
        s1.push(x);
    }

    for (int i = 0; i < n - 1; i++) {
        char op;
        cin >> op;
        s2.push(op);
    }

    auto calc = [&](i32 a, i32 b, char op) -> i32 {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return a / b;
    };

    while (!s2.empty()) {
        i32 n1 = s1.top();
        s1.pop();
        i32 n2 = s1.top();
        s1.pop();
        char op = s2.top();
        s2.pop();

        if (op == '/' && n1 == 0) {
            cout << "ERROR: " << n2 << "/0" << endl;
            return;
        }

        s1.push(calc(n2, n1, op));
    }

    cout << s1.top() << endl;
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
