#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    // 无向图邻接表
    vector<vector<int> > adj(n + 1);
    // vector<int> adj [100005];
    // 记录每个节点的度数
    vector<int> degree(n + 1, 0);
    // 图： 入度 出度
    // 无向图：度-> 当前节点和多少个节点有直接关系

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int d;
            cin >> d;
            adj[i].push_back(d);
            adj[d].push_back(i); // 无向图，双向边
            //a -> b;
            //b -> a;
            degree[i]++;
            degree[d]++;
        }
    }

    // 在树中，根节点的度数应该为1（只有一个子节点），叶子节点度数也是1
    // 但如果只有1个节点，度数为0
    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            root = i;
            break;
        }
    }

    // BFS找最远节点
    int ans = root, max_depth = 0;
    queue<pair<int, int> > q;
    q.push({root, 0});

    vector<bool> vis(n + 1, false);
    vis[root] = true;

    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();

        if (d > max_depth) {
            max_depth = d;
            ans = u;
        }

        for (int v: adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push({v, d + 1});
            }
        }
    }
    //    1
    //   2  3
    //  4 5 6 7
    // [1]  [2]  [3]  [4]  [5]  [6]  [7]  层序遍历
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
