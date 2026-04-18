#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i] = A[i] * A[i];
    }

    sort(S.begin(), S.end());
    ll ans = LLONG_MAX;
    for (int i = 0; i + M - 1 < N; i++) {
        ll diff = S[i + M - 1] - S[i];
        if (diff < ans)
            ans = diff;
    }

    cout << ans << "\n";
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
