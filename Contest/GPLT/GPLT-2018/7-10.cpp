#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
vector<int> adj[100005];

void solve() {
    int root, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p == -1) root = i;
        else adj[p].push_back(i);
    }

    queue<int> q;
    q.push(root);
    int level = 0;
    vector<int> lastgen;

    while (!q.empty()) {
        const auto &sz = q.size();
        level++;
        lastgen.clear();
        for (int i = 0; i < sz; i++) {
            int cur = q.front();
            q.pop();
            lastgen.push_back(cur);
            for (int child: adj[cur]) q.push(child);
        }
    }

    cout << level << endl;
    sort(lastgen.begin(), lastgen.end());
    for (int i = 0; i < lastgen.size(); i++) {
        cout << lastgen[i] << (i == lastgen.size() - 1 ? "" : " ");
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
