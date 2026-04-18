#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    n *= 10;
    k *= 630;
    if (n >= k) cout << "SHENLILINHUA WO LAI LA!!!" << endl;
    else cout << "SHENLILINHUA DENG DENG WO!!!" << endl;
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
