#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<int> S(n);
    S[1] = v[1];
    for (int i = 2; i <= n; i++) {
        S[i] = S[i - 1] + v[i];
    }
    int t;
    cin >> t;
    while (t--) {
        int l,r;
        cin >> l >> r;
        cout << S[r] - S[l-1] << endl;
    }
    return 0;
}