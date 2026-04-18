#include<bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int> db;
    while (n--) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            db[x]++;
        }
    }
    vector<pair<int, int> > v;
    for (const auto &[x,y]: db) {
        v.emplace_back(x, y);
        //cout << x << ":" << y << endl;
    }
    sort(v.begin(), v.end(), cmp());
    for (const auto &[x,y]: v) {
        //cout << x << ":" << y << endl;
    }
    cout << v.back().first << " " << v.back().second << endl;
}
