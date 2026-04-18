#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int len = str.size();
    int mid = len / 2;
    string pre, next;
    pre = str.substr(0, mid);
    map<char, int> mp;
    for (int i = 0; i < 26; i++) {
        mp[(i + 'a')] = (i + 1);
    }
    if (len & 1) {
        next = str.substr(mid + 1, mid);
    } else {
        next = str.substr(mid, mid);
    }
    reverse(next.begin(), next.end());
    int sum = 0;
    for (int i = 0; i < mid; i++) {
        int tmp1 = (mp[pre[i]] + 26 - mp[next[i]]) % 26;
        int tmp2 = (mp[next[i]] + 26 - mp[pre[i]]) % 26;
        sum += min(tmp1, tmp2);
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
