#include<bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return a.first + a.second < b.first + b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int> > cow(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> cow[i].first >> cow[i].second;
    }
    sort(cow.begin(), cow.end(), cmp());
    int res = -2e9,tot = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, tot - cow[i].second);
        tot += cow[i].first;
    }
    cout << res << endl;
    return 0;
}
