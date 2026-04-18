#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    queue<int> que;
    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            que.push(x);
        } else if (op == 2) {
            //if (!que.empty())
                que.pop();
        } else if (op == 3) {
            cin >> x;
            if (!que.empty()) {
                que.front() -= x;
                if (que.front() <= 0) {
                    que.pop();
                }
            }
        } else if (op == 4) {
            if (!que.empty()) cout << que.front() << endl;
            else cout << "0" << endl;
        }
    }
    return 0;
}
