#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    const i32 INF = 4'000'000'000'000'000'000LL;
    vector<char> sex(n + 1);
    vector<vector<i32> > dist(n + 1, vector<i32>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    auto parse = [&](const string &s) -> pair<int, i32> {
        int v = 0, p = 0;
        while (s[p] != ':') {
            v = v * 10 + (s[p] - '0');
            p++;
        }
        p++;
        i32 w = 0;
        while (p < (int) s.size()) {
            w = w * 10 + (s[p] - '0');
            p++;
        }
        return {v, w};
    };

    for (int i = 1; i <= n; i++) {
        char c;
        int k;
        cin >> c >> k;
        sex[i] = c;
        for (int j = 0; j < k; j++) {
            string s;
            cin >> s;
            auto [v, w] = parse(s);
            dist[i][v] = min(dist[i][v], w);
        }
    }

    // Floyd 求任意两点最短路
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] >= INF / 2) continue;
            for (int j = 1; j <= n; j++) {
                if (dist[k][j] >= INF / 2) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<int> fem, male;
    for (int i = 1; i <= n; i++) {
        if (sex[i] == 'F') fem.emplace_back(i);
        else male.emplace_back(i);
    }

    auto get = [&](const vector<int> &tar, const vector<int> &src) -> vector<int> {
        vector<int> ans;
        i32 best = INF;
        for (int x: tar) {
            i32 mx = 0;
            for (int y: src) {
                mx = max(mx, dist[y][x]); // x 在 y 眼中的距离 = y -> x
            }
            if (ans.empty() || mx < best) {
                best = mx;
                ans.clear();
                ans.emplace_back(x);
            } else if (mx == best) {
                ans.emplace_back(x);
            }
        }
        return ans;
    };

    auto print = [&](const vector<int> &a) {
        for (int i = 0; i < (int) a.size(); i++) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << endl;
    };

    auto ansF = get(fem, male);
    auto ansM = get(male, fem);

    print(ansF);
    print(ansM);
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
