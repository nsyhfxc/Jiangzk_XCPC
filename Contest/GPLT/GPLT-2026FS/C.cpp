#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int d, f, b;
    char c;
    string l;
    cin >> d >> c >> l >> f >> b;
    int sum = 0;
    int p = 0;
    if (c == 'Z') {
        cout << "0" << endl;
        return;
    }
    sum = max(d, 500);
    if (c == 'F') {
        sum *= 2.0;
        p += 200;
    } else if (c == 'C') {
        sum *= 1.5;
    } else if (c == 'Y') {
        sum *= 1.0;
    } else if (c == 'D') {
        sum *= 0.5;
    }
    if (l == "Platinum") {
        sum *= 1.5;
    } else if (l == "Gold") {
        sum *= 1.25;
    } else if (l == "Silver") {
        sum *= 1.10;
    } else sum *= 1.0;

    if (c == 'F') {
        sum += p;
    }
    if (l == "Platinum") {
        sum = min(sum, 15000);
    } else sum = min(sum, 10000);
    if (f == b) {
        sum += 500;
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
