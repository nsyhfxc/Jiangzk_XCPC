#include <bits/stdc++.h>
using namespace std;
using ll = long long;

i32 qmi(i32 a, i32 b) {
    i32 res = 1;
    while (b) {
        if (b & 1) res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    i32 n;
    cin >> n;
    vector<pair<i32, i32> > a;
    for (int i = 1; i < 31; i++) {
        i32 sum = 0, j = 1;
        while (sum <= n) {
            sum += qmi(j, i);
            if (sum == n) {
                a.emplace_back(i, j);
                break;
            }
            j++;
        }
    }
    if (a.empty()) {
        cout << "Impossible for " << n << ".";
        return 0;
    }
    const auto c = a[a.size() - 1].second;
    const auto b = a[a.size() - 1].first;
    for (int i = 1; i <= c; i++) {
        cout << (i == 1 ? "" : "+") << i << "^" << b;
    }
    return 0;
}
