#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct Rec {
    string name, id;
    int tm, ord;
};

void solve() {
    int D, P;
    cin >> D >> P;

    unordered_map<string, int> last;
    unordered_set<string> vis;
    vector<pair<string, string> > sick;

    auto chk = [&](const string &id) {
        if (id.size() != 18) return false;
        for (char c: id) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    };

    auto get_tm = [&](const string &s) {
        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        return h * 60 + m;
    };

    for (int day = 1; day <= D; day++) {
        int T, S;
        cin >> T >> S;

        vector<Rec> recs;
        recs.reserve(T);

        for (int i = 0; i < T; i++) {
            string name, id, ts;
            int body;
            cin >> name >> id >> body >> ts;

            bool ok = chk(id);

            if (ok && body == 1 && !vis.count(id)) {
                vis.emplace(id);
                sick.emplace_back(name, id);
            }

            if (ok) {
                recs.emplace_back(Rec{name, id, get_tm(ts), i});
            }
        }

        sort(recs.begin(), recs.end(), [&](const Rec &a, const Rec &b) {
            if (a.tm != b.tm) return a.tm < b.tm;
            return a.ord < b.ord;
        });

        for (auto &r: recs) {
            if (S == 0) break;
            if (!last.count(r.id) || day - last[r.id] > P) {
                cout << r.name << ' ' << r.id << endl;
                last[r.id] = day;
                S--;
            }
        }
    }

    for (auto &[name, id]: sick) {
        cout << name << ' ' << id << endl;
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
