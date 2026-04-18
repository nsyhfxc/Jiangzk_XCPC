#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    int L1 = 0, L2 = 0, L3 = 0;
    for (int i = 1; i <= 8; i++) {
        int x;
        cin >> x;
        L1 += x;
    }
    for (int i = 1; i <= 4; i++) {
        int x;
        cin >> x;
        L2 += x;
    }
    for (int i = 1; i <= 3; i++) {
        int x;
        cin >> x;
        L3 += x;
    }
    int sum = 0;
    sum += L1;
    if (L1 > 80) {
        sum += L2;
    }
    if (L1 > 80 && L2 > 40) {
        sum += L3;
    }
    cout << sum << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
