#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

struct cmp {
    bool operator()(const pair<i32, i32> &x, const pair<i32, i32> &y) const {
        return x.first > y.first;
    }
};

void solve() {
    i32 n;
    cin >> n;
    vector<i32> arr(n);
    unordered_map<i32, i32> mp;
    for (i32 i = 0; i < n; ++i) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    vector<pair<i32, i32> > vals(mp.begin(), mp.end());
    sort(vals.begin(), vals.end(), cmp());

    int winnum = -1;
    for (const auto &[x,y]: vals) {
        if (y % 2 == 1) {
            winnum = x;
            break;
        }
    }

    if (winnum == -1) {
        for (int i = 0; i < n; ++i) {
            cout << "0";
        }
        cout << endl;
    } else {
        string res(n, '0');
        for (int i = 0; i < n; ++i) {
            if (arr[i] == winnum) res[i] = '1';
        }
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}
