#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n ;
    cin >> n;
    if (n == 1 || n == 3) {
        cout << "YES" << endl;
        for (int i = 1;i <= n;++i) {
            cout << i << (i == n ? endl : ' ');
        }
    }
    else cout << "NO" << endl;
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
