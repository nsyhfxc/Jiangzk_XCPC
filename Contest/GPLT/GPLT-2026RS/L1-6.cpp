#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    vector<i32> arr(9);
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }
    arr[1] += arr[0] / 2;
    arr[0] %= 2;
    cout << arr[0] << " ";

    arr[2] += arr[1] / 3;
    arr[1] %= 3;
    cout << arr[1] << " ";

    arr[3] += arr[2] / 2;
    arr[2] %= 2;
    cout << arr[2] << " ";

    arr[4] += arr[3] / 3;
    arr[3] %= 3;
    cout << arr[3] << " ";

    arr[5] += arr[4] / 2;
    arr[4] %= 2;
    cout << arr[4] << " ";

    arr[6] += arr[5] / 3;
    arr[5] %= 3;
    cout << arr[5] << " ";

    arr[7] += arr[6] / 2;
    arr[6] %= 2;
    cout << arr[6] << " ";

    arr[8] += arr[7] / 3;
    arr[7] %= 3;
    cout << arr[7] << " ";

    cout << arr[8];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
