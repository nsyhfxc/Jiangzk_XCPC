#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<i32, i32> > girls(n);
    for (int i = 0; i < n; i++) {
        cin >> girls[i].first >> girls[i].second;
    }
    sort(girls.begin(), girls.end(), [&](const pair<i32, i32> &a, const pair<i32, i32> &b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    int cnt = 0;
    int cost = 0;
    for (int i = 0; i < n; i++) {
        if (girls[i].first <= cnt) {
            cnt++;
        }
        else {
            cost += girls[i].second;
            cnt++;
        }
    }
    cout << cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
