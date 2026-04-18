#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'

void solve() {
    unordered_map<int, int> db;
    for (int i = 0; i < 24; ++i) {
        int x;
        cin >> x;
        db[i] = x;
    }
    int num;
    while (cin >> num) {
        if (num < 0 || num > 23) {
            break;
        }
        cout << db[num] << " " << ((db[num] > 50) ? "Yes" : "No") << endl;
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
