#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    map<char, int> idx;
    map<char, int> best;
    for (int i = 1; i <= n; i++) {
        char d;
        int q;
        cin >> d >> q;
        if (q >= 60 && q > best[d]) {
            best[d] = q;
            idx[d] = i;
        }
    }
    int sum = 0;
    for (char i = 'A'; i <= 'F'; i++) {
        if (!best.count(i)) {
            cout << -1 << endl;
            return;
        }
        sum += best[i];
    }

    if (sum < 420) {
        cout << -1 << endl;
        return;
    }

    for (char i = 'A'; i <= 'F'; i++) {
        if (i) cout << ' ';
        cout << idx[i];
    }
    cout << endl;
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
