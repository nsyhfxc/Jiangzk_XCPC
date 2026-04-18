#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    auto to_vec = [&](const string &str) {
        vector<int> res;
        for (int i = (int) str.size() - 1; i >= 0; --i) {
            char c = str[i];
            int val;
            if (c >= '0' && c <= '9') val = c - '0';
            else val = toupper(c) - 'A' + 10;
            res.push_back(val);
        }
        return res;
    };
    vector<int> a = to_vec(s);
    auto is_palin = [&](const vector<int> &v) {
        int sz = (int) v.size();
        for (int i = 0; i < sz / 2; ++i) {
            if (v[i] != v[sz - 1 - i]) return false;
        }
        return true;
    };
    auto add = [&](const vector<int> &v) {
        vector<int> r = v;
        reverse(r.begin(), r.end());
        vector<int> res;
        int carry = 0;
        int len = (int) v.size();
        for (int i = 0; i < len || carry; ++i) {
            int sum = carry;
            if (i < len) sum += v[i];
            if (i < len) sum += r[i];
            res.push_back(sum % n);
            carry = sum / n;
        }
        return res;
    };

    int step = 0;
    for (; step <= 30; ++step) {
        if (is_palin(a)) break;
        if (step == 30) break;
        a = add(a);
    }

    if (is_palin(a)) {
        cout << "STEP=" << step << endl;
    } else {
        cout << "Impossible!" << endl;
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
}
