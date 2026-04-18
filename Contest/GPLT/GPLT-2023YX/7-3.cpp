#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool fu = false;
    if (n < 0) fu = true;
    n = abs(n);
    if (fu) cout << "-";
    queue<int> que;
    while (n) {
        que.push(n % 10);
        n /= 10;
    }
    bool flag = false;
    while (!que.empty()) {
        if (que.front() != 0) {
            flag = true;
        }
        if (flag) {
            cout << que.front();
            que.pop();
            continue;
        }
        que.pop();
    }
    return 0;
}
