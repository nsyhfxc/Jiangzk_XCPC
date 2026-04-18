#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    int x, y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }

    i32 tot = x * y;
    int cnt = 0;
    for (i32 p = x; p <= y; p += x) {
        if (tot % p == 0) {
            i32 q = tot / p;
            if (gcd(p, q) == x) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
