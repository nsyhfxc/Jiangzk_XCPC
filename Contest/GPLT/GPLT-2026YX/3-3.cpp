#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

i32 query(const string &type, int i, int j) {
    cout << type << " " << i << " " << j << endl;
    i32 res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<i32> xor_with_1(n + 1);
    for (int i = 2; i <= n; ++i) {
        xor_with_1[i] = query("XOR", 1, i);
    }
    i32 and12 = query("AND", 1, 2);
    i32 and23 = query("AND", 2, 3);
    i32 and13 = query("AND", 1, 3);
    i32 s12 = xor_with_1[2] + 2 * and12;
    i32 s13 = xor_with_1[3] + 2 * and13;
    i32 s23 = (xor_with_1[2] ^ xor_with_1[3]) + 2 * and23;
    vector<i32> A(n + 1);
    A[1] = (s12 + s13 - s23) / 2;
    for (int i = 2; i <= n; ++i) {
        A[i] = A[1] ^ xor_with_1[i];
    }
    cout << "!";
    for (int i = 1; i <= n; ++i) {
        cout << " " << A[i];
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
