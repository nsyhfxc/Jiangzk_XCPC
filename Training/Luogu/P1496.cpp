#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > seg(n);
    for (int i = 0; i < n; i++) {
        cin >> seg[i].first >> seg[i].second;
    }

    sort(seg.begin(), seg.end());
    long long ans = 0;
    long long l = seg[0].first, r = seg[0].second;
    for (int i = 1; i < n; i++) {
        if (seg[i].first <= r) {
            r = max(r, static_cast<long long>(seg[i].second));
        } else {
            ans += r - l;
            l = seg[i].first;
            r = seg[i].second;
        }
    }
    ans += r - l;
    cout << ans << endl;
    return 0;
}
