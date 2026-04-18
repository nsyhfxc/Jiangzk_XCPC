#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int tot = 1 << n;
    vector<pair<int, int> > left(tot / 2);
    vector<pair<int, int> > right(tot / 2);
    for (int i = 0; i < left.size(); i++) {
        left[i].first = i;
        cin >> left[i].second;
    }
    for (int i = 0; i < right.size(); i++) {
        right[i].first = i + (tot / 2);
        cin >> right[i].second;
    }
    sort(left.begin(), left.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    });
    sort(right.begin(), right.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    });
    int l = left[0].second;
    int r = right[0].second;
    if (l > r) {
        cout << right[0].first + 1 << endl;
    } else {
        cout << left[0].first + 1 << endl;
    }
    return 0;
}
