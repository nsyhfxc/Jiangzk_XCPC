#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    while (m--) {
        int q;
        cin >> q;
        auto it = lower_bound(arr.begin(), arr.end(), q);
        cout << (arr[it - arr.begin()] == q ? it - arr.begin() + 1 : -1) << " ";
    }
    return 0;
}
