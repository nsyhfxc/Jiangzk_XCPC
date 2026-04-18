#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct Node {
    i32 cnt;
    vector<i32> res;

    bool operator<(const node &other) const {
        if (this->cnt != other.cnt) {
            return this->cnt > other.cnt;
        }
        return this->res < other.res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    map<vector<i32>, i32> db;
    for (int i = 1; i <= n; i++) {
        vector<i32> temp;
        int x;
        for (int j = 1; j <= m; j++) {
            cin >> x;
            temp.push_back(x);
        }
        db[temp]++;
    }
    cout << db.size() << endl;
    vector<node> arr;
    for (const auto &[x,y]: db) {
        arr.push_back({y, x});
    }
    sort(arr.begin(), arr.end());
    for (const auto &[x,y]: arr) {
        cout << x << " ";
        bool flag = false;
        for (const auto i: y) {
            cout << (flag ? " " : "") << i;
            flag = true;
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
