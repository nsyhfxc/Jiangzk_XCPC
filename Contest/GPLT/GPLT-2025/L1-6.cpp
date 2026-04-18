#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    map<char, int> mp; //char->int
    int cnt = 1;
    for (char c = 'a'; c <= 'z'; c++) {
        mp[c] = cnt;
        cnt++;
    }
    cnt = 1;
    map<int, char> db; //int->char
    for (int i = 1; i <= 26; i++) {
        db[i] = char(cnt + 'a' - 1);
        cnt++;
    }
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.push_back(db[x]);
    }

    for (int i = 1, op, l1, l2; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> l1;
            string s1;
            for (int j = 1; j <= l1; j++) {
                int x;
                cin >> x;
                s1.push_back(db[x]);
            }
            cin >> l2;
            string s2;
            for (int j = 1; j <= l2; j++) {
                int x;
                cin >> x;
                s2.push_back(db[x]);
            }
            if (s.find(s1) != string::npos) {
                size_t pos = s.find(s1);
                s.replace(pos, s1.size(), s2);
            }
        } else if (op == 2) {
            string nes;
            for (int j = 0; j < s.size() - 1; j++) {
                int sum = mp[s[j]] + mp[s[j + 1]];
                if (sum % 2 == 0) {
                    nes.push_back(s[j]);
                    nes.push_back(db[sum / 2]);
                } else nes.push_back(s[j]);
            }
            nes.push_back(s.back());
            s = nes;
        } else if (op == 3) {
            int l, r;
            cin >> l >> r;
            l--;
            reverse(s.begin() + l, s.begin() + r);
        }
    }
    bool flag = false;
    for (const auto c: s) {
        cout << (flag ? " " : "") << mp[c];
        flag = true;
    }
    cout << endl;
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
