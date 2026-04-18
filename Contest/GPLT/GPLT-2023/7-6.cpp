#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        int l, r;
        string pre, suf;
        cin >> l >> r >> pre >> suf;

        string clip = s.substr(l - 1, r - l + 1);
        s.erase(l - 1, r - l + 1);

        string pat = pre + suf;
        size_t pos = s.find(pat);

        if (pos == string::npos) {
            s += clip;
        } else {
            s.insert(pos + pre.size(), clip);
        }
    }

    cout << s << endl;
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