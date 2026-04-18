#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int num[101];
    int pos[101][11][11];
    int mx = 0, pre = 0;
    int x = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        mx = max(mx, num[i]);
    }
    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= n; k++) {
                if (i <= num[k]) {
                    if (pre == k)
                        x += 2;
                    else
                        x++;
                    pos[k][i][j] = x;
                    pre = k;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << "#" << i << endl;
        for (int j = 1; j <= num[i]; j++) {
            for (int k = 1; k <= 10; k++) {
                if (k <= 9)
                    cout << pos[i][j][k] << " ";
                else
                    cout << pos[i][j][k] << endl;
            }
        }
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
}
