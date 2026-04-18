#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;
constexpr int OFFSET = 1e6;
bool exist[2000005];

void func(vector<int> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> v0, v1, v2;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == 0) v0.push_back(x);
        if (y == 1) v1.push_back(x);
        if (y == 2) v2.push_back(x);
    }
    func(v0);
    func(v1);
    func(v2);
    for (const int &x: v2) exist[x + OFFSET] = true;
    bool found = false;
    for (const int &x1: v1) {
        for (const int &x0: v0) {
            int tar = 2 * x1 - x0;
            if (tar > 1e6) continue;
            if (tar < -1e6) break;
            if (exist[tar + OFFSET]) {
                found = true;
                cout << "[" << x0 << ", 0] [" << x1 << ", 1] [" << tar << ", 2]\n";
            }
        }
    }

    if (!found) cout << "-1" << endl;
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
