#include <bits/stdc++.h>
using namespace std;

struct Node {
    int addr;
    int key;
    int next;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int head, N;
    cin >> head >> N;
    unordered_map<int, Node> mp;
    for (int i = 0; i < N; i++) {
        int addr, key, next;
        cin >> addr >> key >> next;
        mp[addr] = {addr, key, next};
    }
    unordered_set<int> vis;
    vector<Node> keep, removed;

    int cur = head;
    while (cur != -1) {
        Node node = mp[cur];
        int ab = abs(node.key);
        if (!vis.count(ab)) {
            vis.insert(ab);
            keep.push_back(node);
        } else {
            removed.push_back(node);
        }
        cur = node.next;
    }
    for (int i = 0; i < static_cast<int>(keep.size()); i++) {
        printf("%05d %d ", keep[i].addr, keep[i].key);
        if (i + 1 < static_cast<int>(keep.size()))
            printf("%05d\n", keep[i + 1].addr);
        else
            printf("-1\n");
    }
    for (int i = 0; i < static_cast<int>(removed.size()); i++) {
        printf("%05d %d ", removed[i].addr, removed[i].key);
        if (i + 1 < static_cast<int>(removed.size()))
            printf("%05d\n", removed[i + 1].addr);
        else
            printf("-1\n");
    }

    return 0;
}
