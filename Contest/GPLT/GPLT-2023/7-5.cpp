#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<i32> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    while (k--) {
        int ac = 0, wa = 0, zero = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                zero++;
            } else {
                if (x == arr[i]) {
                    ac++;
                } else wa++;
            }
        }
        //cout << ac << " " << wa << " " << zero << endl;
        if (ac >= 1 && wa == 0) {
            cout << "Da Jiang!!!" << endl;
        }else cout << "Ai Ya" << endl;
    }
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
