#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int a1, a2, n;
    cin >> a1 >> a2 >> n;

    vector<int> arr;
    arr.emplace_back(a1);
    if (n >= 2) arr.emplace_back(a2);

    int i = 0;
    while (arr.size() < n) {
        int x = arr[i] * arr[i + 1];
        if (x >= 10) {
            arr.emplace_back(x / 10);
            if (arr.size() < n) {
                arr.emplace_back(x % 10);
            }
        } else {
            arr.emplace_back(x);
        }
        i++;
    }

    for (int j = 0; j < n; j++) {
        if (j) cout << ' ';
        cout << arr[j];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
