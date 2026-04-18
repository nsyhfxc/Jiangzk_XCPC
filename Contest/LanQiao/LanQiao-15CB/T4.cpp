#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using u32 = unsigned long long;

void solve() {
    u32 n;
    double d;
    cin >> n >> d;
    cout << round(d * pow(2, n)) << endl;
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
