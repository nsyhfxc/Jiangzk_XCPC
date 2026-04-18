#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<string> > nums(n);
    set<string> symbols;

    auto split = [&](const string &s)-> vector<string> {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, '.')) {
            res.push_back(item);
        }
        return res;
    };

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        nums[i] = split(s);
        for (const string &sym: nums[i]) {
            symbols.insert(sym);
        }
    }

    map<string, set<string> > adj;
    map<string, int> indegree;
    for (const string &sym: symbols) {
        indegree[sym] = 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        const auto &a = nums[i];
        const auto &b = nums[i + 1];
        if (a.size() == b.size()) {
            for (int j = 0; j < a.size(); ++j) {
                if (a[j] != b[j]) {
                    if (!adj[a[j]].count(b[j])) {
                        adj[a[j]].insert(b[j]);
                        indegree[b[j]]++;
                    }
                    break;
                }
            }
        }
    }
    priority_queue<string, vector<string>, greater<string> > pq;
    for (auto const &[sym, count]: indegree) {
        if (count == 0) {
            pq.push(sym);
        }
    }

    vector<string> result;
    while (!pq.empty()) {
        string u = pq.top();
        pq.pop();
        result.push_back(u);

        for (const string &v: adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                pq.push(v);
            }
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : ".");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
