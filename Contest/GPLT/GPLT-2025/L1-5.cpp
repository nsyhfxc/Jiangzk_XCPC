#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    string s;
    cin >> s;
    map<char, int> mp, num;
    for (char c = 'a'; c <= 'z'; c++) {
        int x;
        cin >> x;
        mp[c] = x;
    }
    int ans = 0;
    for (auto i: s) {
        num[i]++;
        ans += mp[i];
    }
    for (char c = 'a'; c <= 'z'; c++) {
        cout << num[c] << " \n"[c == 'z'];
    }
    cout << ans;
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
