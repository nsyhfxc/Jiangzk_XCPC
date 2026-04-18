#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    vector<int> p(4);
    int min_t, diff;
    for (int i = 0; i < 4; ++i) {
        cin >> p[i];
    }
    cin >> min_t >> diff;
    int max_p = *max_element(p.begin(), p.end());
    auto is_bad = [&](int val) {
        return val < min_t || (max_p - val) > diff;
    };
    int cnt = 0;
    int index = -1;
    for (int i = 0; i < 4; ++i) {
        if (is_bad(p[i])) {
            cnt++;
            index = i + 1;
        }
    }
    if (cnt == 0) {
        cout << "Normal" << endl;
    } else if (cnt == 1) {
        cout << "Warning: please check #" << index << "!" << endl;
    } else {
        cout << "Warning: please check all the tires!" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
