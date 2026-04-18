#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, q;
    map<string, vector<string> > mp;
    string s;

    auto work = [](string s) -> string {
        string res = "";
        int sz = s.size();
        s = " " + s;
        for (int i = 1; i <= sz; i++) {
            if (isalpha(s[i]) && s[i - 1] == ' ') {
                res += s[i];
            }
        }
        return res;
    };

    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        mp[work(s)].emplace_back(s);
    }
    for (auto &[_, v]: mp) {
        sort(begin(v), end(v));
    }

    cin >> q;
    cin.ignore();
    for (int i = 1; i <= q; i++) {
        getline(cin, s);
        string t = work(s);
        if (!mp.count(t)) {
            cout << s << endl;
        } else {
            int sz = mp[t].size();
            for (int j = 0; j < sz; j++) {
                if (j > 0) {
                    cout << "|";
                }
                cout << mp[t][j];
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
