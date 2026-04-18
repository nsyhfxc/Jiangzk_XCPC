#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct node {
    int val, l, r;

    explicit node(int v = 0, int L = -1, int R = -1) {
        this->val = v;
        this->l = L;
        this->r = R;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> post(n), in(n);
    for (int i = 0; i < n; i++) cin >> post[i];
    for (int i = 0; i < n; i++) cin >> in[i];

    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) pos[in[i]] = i;

    vector<node> tr;
    tr.reserve(n);

    function<int(int, int, int, int)> build = [&](int pl, int pr, int il, int ir) -> int {
        if (pl > pr || il > ir) return -1;
        int rootVal = post[pr];
        int k = pos[rootVal];
        int leftSz = k - il;

        int cur = (int) tr.size();
        tr.emplace_back(rootVal, -1, -1);
        tr[cur].l = build(pl, pl + leftSz - 1, il, k - 1);
        tr[cur].r = build(pl + leftSz, pr - 1, k + 1, ir);
        return cur;
    };

    int root = build(0, n - 1, 0, n - 1);

    vector<int> ans;
    queue<int> q;
    if (root != -1) q.emplace(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.emplace_back(tr[u].val);
        if (tr[u].l != -1) q.emplace(tr[u].l);
        if (tr[u].r != -1) q.emplace(tr[u].r);
    }

    for (size_t i = 0; i < ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
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
