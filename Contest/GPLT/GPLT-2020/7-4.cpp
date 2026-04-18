#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<double> arr;
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        arr.emplace_back(1 / x);
    }
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double res = 1 / (sum / n);
    cout << fixed << setprecision(2) << res << endl;
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
