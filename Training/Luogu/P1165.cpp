#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    stack<int> stk;
    multiset<int>st;
    while (n--) {
        int op, x;
        cin >> op;
        if (op == 0) {
            cin >> x;
            stk.push(x);
            st.insert(x);
        } else if (op == 1) {
            if (!stk.empty()) {
                int tp = stk.top();
                stk.pop();
                st.erase(tp);
            }
        } else if (op == 2) {
            if (!stk.empty()) {
                cout << *st.rbegin() << endl;
            } else cout << "0" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
