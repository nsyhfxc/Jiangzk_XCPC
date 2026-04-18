#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve() {
    int T,S,t;
    cin >> T >> S >> t;//T室外 S状态 t室内
    if (T > 35 && S && t >= 33) {
        cout << "Bu Tie" << endl;
        cout << T << endl;
        return;
    }
    if (T > 35 && !S && t >= 33) {
        cout << "Shi Nei" << endl;
        cout << T << endl;
        return;
    }
    if (S &&(T <= 35 || t < 33)) {
        cout << "Bu Re" << endl;
        cout << t << endl;
        return;
    }
    cout << "Shu Shi" << endl;
    cout << t << endl;
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
