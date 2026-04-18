#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    int maxnum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        maxnum = max(maxnum, arr[i]);
    }
    cout << static_cast<long long>(maxnum) * (n - 2) + arr[1] + arr[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
