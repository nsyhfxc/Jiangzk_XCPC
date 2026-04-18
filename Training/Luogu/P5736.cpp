#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
vector<int> prime, minp;

void sieve(int n = 1e7) {
    minp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto j: prime) {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x: arr) cin >> x;
    for (auto x: arr) {
        if (isprime(x)) {
            cout << x << ' ';
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    solve();
    return 0;
}
