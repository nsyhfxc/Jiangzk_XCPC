#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    i32 n, m;
    cin >> n >> m;

    vector<i32> a(n + 1, 0);
    i32 sum = 0;
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            i32 x, y;
            cin >> x >> y;
            sum = sum - a[x] + y;
            a[x] = y;
        } else if (tp == 2) {
            long long x, y;
            cin >> x >> y;
            a[x] += y;
            sum += y;
        } else if (tp == 3) {
            long long y;
            cin >> y;
            sum = n * y;
            for (int i = 1; i <= n; i++) {
                a[i] = y;
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
