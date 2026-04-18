#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), [&](const int &a, const int &b) {
        return a < b;
    });
    i32 l = arr.front(), r = arr.back();
    while (l <= r) {
        const int mid = l + (r - l) / 2;
        i32 sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(arr[i] - mid, 0);
        }
        if (sum < m) r = mid - 1;
        else l = mid + 1;
    }
    cout << l - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
