#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    while (m--) {
        int q;
        cin >> q;
        auto find = [&](const int k) {
            int l = 0, r = n + 1;
            while (l + 1 < r) {
                int mid = (l + r) >> 1;
                if (v[mid] >= k) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return r;
        };
        if (v[find(q)] == q) {
            cout << find(q) << " ";
        } else {
            cout << "-1" << " ";
        }
    }
    return 0;
}
