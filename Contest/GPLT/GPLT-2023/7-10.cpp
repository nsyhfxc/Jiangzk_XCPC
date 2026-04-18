#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<string> name(n);
    vector<int> rem(n), ans(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> name[i] >> rem[i];
    }

    struct Node {
        int n, id;
    };
    struct Cmp {
        bool operator()(const Node &a, const Node &b) const {
            if (a.n != b.n) return a.n < b.n; // 大顶堆：人数多的优先
            return a.id > b.id; // 人数相同：输入顺序靠前优先
        }
    };

    priority_queue<Node, vector<Node>, Cmp> pq;
    for (int i = 0; i < n; i++) {
        pq.emplace(Node{rem[i], i});
    }

    // buckets[r]：当前剩余座位数为 r 的赛场编号集合（r in [1, C-1]）
    vector<set<int> > buckets(c);
    vector<int> room_rem(1, 0); // 1-based，room_rem[room_id] = 剩余座位
    int room_cnt = 0;

    auto open_room = [&](int fill) {
        ++room_cnt;
        room_rem.emplace_back(c - fill);
        int r = c - fill;
        if (r > 0) buckets[r].emplace(room_cnt);
        return room_cnt;
    };

    auto alloc_to_room = [&](int rid, int take) {
        int old_r = room_rem[rid];
        if (old_r > 0) buckets[old_r].erase(rid);
        int new_r = old_r - take;
        room_rem[rid] = new_r;
        if (new_r > 0) buckets[new_r].emplace(rid);
    };

    auto find_room = [&](int need) -> int {
        int rid = INT_MAX;
        for (int r = need; r <= c - 1; r++) {
            if (!buckets[r].empty()) {
                rid = min(rid, *buckets[r].begin());
            }
        }
        return rid == INT_MAX ? -1 : rid;
    };

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int n = cur.n, id = cur.id;

        if (n >= c) {
            open_room(c); // 开新赛场，放满 C 人
            ans[id]++;
            n -= c;
            if (n > 0) pq.emplace(Node{n, id});
        } else {
            int rid = find_room(n);
            if (rid == -1) {
                open_room(n); // 找不到可容纳的非空赛场，开新赛场
            } else {
                alloc_to_room(rid, n); // 放入编号最小且能容纳的赛场
            }
            ans[id]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << name[i] << ' ' << ans[i] << endl;
    }
    cout << room_cnt << endl;
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
