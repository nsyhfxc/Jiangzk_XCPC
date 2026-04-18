#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    sort(tree.begin(), tree.end());
    int l = 1, r = tree.back();
    auto check = [&](int len) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += tree[i] / len;
        }
        if (sum >= k) return true;
        return false;
    };
    while (r >= l) {
        const int mid = l + (r - l) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << endl;
}
