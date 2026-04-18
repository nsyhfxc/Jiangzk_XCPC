#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    double wei, hei;
    cin >> wei >> hei;
    double bmi = wei / hei / hei;
    cout << fixed << setprecision(1) << bmi << endl;
    cout << ((bmi > 25) ? "PANG" : "Hai Xing") << endl;
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
