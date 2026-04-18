#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
void solve() {
    ll n;
    cin >> n;
    cout << ((n == 1) ? 1 :((n - 1) * n)) << endl;
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