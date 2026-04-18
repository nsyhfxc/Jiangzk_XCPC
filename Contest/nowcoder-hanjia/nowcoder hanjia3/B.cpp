#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<i32> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            i32 x = gcd(arr[i], arr[j]);
            if (x > 1) {
                cout << arr[i] << ' ' << arr[j] << endl;
                return;
            }
        }
    }
    cout << "-1" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}
