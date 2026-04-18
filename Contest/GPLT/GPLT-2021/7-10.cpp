#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<queue<char> > que(n + 1);
    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for (const auto &c: temp) {
            que[i].push(c);
        }
    }
    stack<char> stk;
    int op;
    while (cin >> op) {
        if (op == -1) {
            break;
        }
        if (op == 0 && !stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        if (stk.size() < s && !que[op].empty()) {
            stk.push(que[op].front());
            que[op].pop();
        } else if (!que[op].empty()) {
            cout << stk.top();
            stk.pop();
            stk.push(que[op].front());
            que[op].pop();
        }
    }
    cout << endl;
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
