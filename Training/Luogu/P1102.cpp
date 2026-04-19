#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 n, c;
    cin >> n >> c;
    vector<i32> a(n);
    unordered_map<i32, i32> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    i32 ans = 0;
    for (int i = 0; i < n; i++) {
        const i32 need = a[i] - c;
        if (mp.count(need)) ans += mp[need];
    }
    cout << ans;
    return 0;
}
