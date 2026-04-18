#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
constexpr int N = 100010;
int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - a[i - 1];
    }
    i32 p = 0, q = 0;
    for (int i = 2; i <= n; i++) {
        if (b[i] > 0) {
            p += b[i];
        } else {
            q += abs(b[i]);
        }
    }
    cout << max(p, q) << endl << abs(q - p) + 1 << endl;
    return 0;
}
