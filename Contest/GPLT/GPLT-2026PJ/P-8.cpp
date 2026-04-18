#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct Info {
    int cnt = 0;
    int first = -1, second = -1;
    bool ok = true;
    bool has_sig = false;
    u32 s1 = 0, s2 = 0;
};

void solve() {
    vector<u32> a;
    i32 x;
    while (cin >> x) {
        if (x == -1) break;
        a.emplace_back((u32) x);
    }

    unordered_map<u32, Info> mp;
    mp.reserve(a.size() * 2 + 1);

    int m = (int) a.size();
    for (int i = 0; i < m; i++) {
        u32 v = a[i];
        auto &info = mp[v];

        info.cnt++;
        if (info.first == -1) info.first = i;
        else if (info.second == -1) info.second = i;

        if (i + 2 >= m) {
            info.ok = false;
            continue;
        }

        u32 t1 = a[i + 1], t2 = a[i + 2];
        if (!info.has_sig) {
            info.has_sig = true;
            info.s1 = t1;
            info.s2 = t2;
        } else if (info.s1 != t1 || info.s2 != t2) {
            info.ok = false;
        }
    }

    int best_second = INT_MAX, best_first = INT_MAX;
    bool found = false;
    u32 ans_v = 0, ans_1 = 0, ans_2 = 0;

    auto upd = [&](int first, int second, u32 v, u32 p1, u32 p2) {
        if (second < best_second || (second == best_second && first < best_first)) {
            best_second = second;
            best_first = first;
            ans_v = v;
            ans_1 = p1;
            ans_2 = p2;
            found = true;
        }
    };

    for (auto &[v, info]: mp) {
        if (info.cnt >= 2 && info.ok && info.has_sig && info.second != -1) {
            upd(info.first, info.second, v, info.s1, info.s2);
        }
    }

    if (!found) {
        cout << "NONE" << endl;
    } else {
        cout << ans_v << ' ' << ans_1 << ' ' << ans_2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
