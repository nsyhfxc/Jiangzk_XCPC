#include <bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

struct Process {
    i32 a, b, c;
};

void solve() {
    i32 n, s;
    cin >> n >> s;
    vector<Process> arr(n + 1);
    for (i32 i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    i32 res = 0;
    i32 sum = 0;
    int l = 1;
    deque<int> mx, mn;
    for (i32 r = 1; r <= n; r++) {
        sum += arr[r].c;
        while (!mx.empty() && arr[mx.back()].a <= arr[r].a) mx.pop_back();
        mx.push_back(r);

        while (!mn.empty() && arr[mn.back()].b >= arr[r].b) mn.pop_back();
        mn.push_back(r);
        while (l <= r) {
            i32 mxA = arr[mx.front()].a;
            i32 mnB = arr[mn.front()].b;

            if (sum <= s && mxA <= mnB) {
                break;
            }
            sum -= arr[l].c;
            if (!mx.empty() && mx.front() == l) mx.pop_front();
            if (!mn.empty() && mn.front() == l) mn.pop_front();
            l++;
        }
        if (l <= r) {
            res = max(res, r - l + 1);
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
