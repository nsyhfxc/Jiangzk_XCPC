#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int r, l;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<TreeNode> tree(n + 2, {0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].l >> tree[i].r;
    }
    queue<pair<int, int> > que;
    que.emplace(1, 1);
    int ans = 0;
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        int index = cur.first;
        int depth = cur.second;
        ans = max(ans, depth);
        if (tree[index].l != 0) {
            que.emplace(tree[index].l, depth + 1);
        }
        if (tree[index].r != 0) {
            que.emplace(tree[index].r, depth + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
