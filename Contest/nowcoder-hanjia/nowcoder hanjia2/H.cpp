#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

vector<vector<int> > getchild(const vector<int> &a) {
    int n = a.size();
    vector<vector<int> > res;
    res.reserve(n * (n + 1) / 2);
    for (int l = 0; l < n; ++l) {
        vector<int> cur;
        for (int r = l; r < n; ++r) {
            cur.push_back(a[r]);
            res.push_back(cur);
        }
    }
    return res;
}


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    auto func = [&](const int &l, const int &r, const vector<int> &s)-> i32 {
        unordered_set<int> dist;
        i32 tot = 0;
        i32 curcnt = 0;
        for (int i = l; i <= r; ++i) {
            if (dist.find(s[i]) == dist.end()) {
                curcnt++;
                dist.insert(s[i]);
            }
            tot += curcnt;
        }
        return tot;
    };
    i32 ans = 0;
    auto v = getchild(arr);
    for (const auto &x: v) {
        ans += func(0, x.size(), x);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
