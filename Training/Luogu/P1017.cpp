#include <bits/stdc++.h>
using namespace std;
static constexpr char DIGIT[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void solve() {
    int n, r;
    cin >> n >> r;
    int base = r;
    int x = n;
    if (x == 0) {
        cout << n << "=0(base" << base << ")\n";
        return;
    }
    vector<int> digits;
    while (x != 0) {
        int rr = x % base;
        x /= base;
        if (rr < 0) {
            rr += abs(base);
            x += 1;
        }
        digits.push_back(rr);
    }
    reverse(digits.begin(), digits.end());
    cout << n << "=";
    for (int d: digits) cout << DIGIT[d];
    cout << "(base" << base << ")\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
