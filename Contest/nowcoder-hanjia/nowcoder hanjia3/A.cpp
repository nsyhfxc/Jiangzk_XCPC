#include <bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    int x;
    cin >> x;
    set<int>st;
    for (int i = 1; i <= 100; i++) {
        st.insert(i * (i + 1));
    }
    cout << (st.count(x) ? "YES" : "NO") << endl;
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
