#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    queue<int> pusher;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pusher.push(x);
    }
    stack<int> box;
    while (!pusher.empty() || !box.empty()) {
        vector<int> branch;
        auto process = [&]() -> void {
            while (branch.size() < k) {
                if (!box.empty()) {
                    if (branch.empty() || box.top() <= branch.back()) {
                        branch.push_back(box.top());
                        box.pop();
                        continue;
                    }
                }
                if (!pusher.empty()) {
                    int cur = pusher.front();
                    if (branch.empty() || cur <= branch.back()) {
                        branch.push_back(cur);
                        pusher.pop();
                    } else {
                        if (box.size() < m) {
                            box.push(cur);
                            pusher.pop();
                        } else {
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
        };
        process();
        for (int i = 0; i < branch.size(); i++) {
            cout << branch[i] << (i == branch.size() - 1 ? "" : " ");
        }
        cout << endl;
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
