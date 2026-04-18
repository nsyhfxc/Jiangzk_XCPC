#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 110;
int n, rd[MAXN];
vector<int> e[MAXN], tp;

bool toposort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!rd[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        tp.push_back(u);
        for (auto v: e[u]) if (--rd[v] == 0) q.push(v);
    }
    return tp.size() == n;
}

int main() {
    cin >> n;
    for (int i = 1, j; i <= n; i++) {
        while (cin >> j && j) {
            e[i].push_back(j);
            rd[j]++;
        }
    }
    toposort();
    for (int i = 0; i < n; i++) cout << tp[i] << " ";
}
