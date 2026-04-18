#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

vector<string> ban;
i32 n, k;
string s, tmp = "*****";

void solve() {
    cin >> n;
    ban.resize(n);
    for (i32 i = 0; i < n; i++) cin >> ban[i];

    cin >> k;
    cin.ignore();
    getline(cin, s);

    i32 cnt = 0;
    for (auto &t: ban) {
        i32 sz = t.size();
        i32 pos = s.find(t);
        while (pos != string::npos) {
            cnt++;
            s = s.substr(0, pos) + tmp + s.substr(pos + sz);
            pos = s.find(t);
        }
    }

    if (cnt >= k) {
        cout << cnt << endl << "He Xie Ni Quan Jia!" << endl;
    } else {
        i32 sz = tmp.size();
        i32 pos = s.find(tmp);
        while (pos != -1) {
            s = s.substr(0, pos) + "<censored>" + s.substr(pos + sz);
            pos = s.find(tmp);
        }
        cout << s << endl;
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
