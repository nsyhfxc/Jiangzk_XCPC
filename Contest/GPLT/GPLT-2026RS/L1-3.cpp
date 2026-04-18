#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    cout << n << endl;
    if (n < 0) {
        cout << "dan ren" << endl;
        return;
    }
    if (n == 0) {
        cout << "xian ren" << endl;
        return;
    }
    cout << "nong ren" << endl;
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
