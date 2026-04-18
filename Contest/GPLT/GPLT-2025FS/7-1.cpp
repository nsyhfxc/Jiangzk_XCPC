#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (const char &ch: s) {
        cnt[ch]++;
    }
    map<char, bool> vis;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        vis[ch] = false;
    }
    string res;
    for (const char &ch: s) {
        cnt[ch]--;
        if (vis[ch]) continue;
        while (!res.empty() && ch > res.back() && cnt[res.back()] > 0) {
            vis[res.back()] = false;
            res.pop_back();
        }
        res.push_back(ch);
        vis[ch] = true;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
