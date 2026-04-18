#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    double roche, r;
    int shuxing;
    cin >> roche >> shuxing >> r;
    if (shuxing == 0) {
        roche *= 2.455;
    } else roche *= 1.26;
    cout << fixed << setprecision(2) << roche << " ";
    cout << (roche >= r ? "T_T" : "^_^") << endl;
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
