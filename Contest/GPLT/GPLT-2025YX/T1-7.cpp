#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pos(n + 1);
    vector<int> room(n + 1);
    vector<int> id(n + 1);

    for (int i = 1; i <= n; ++i) {
        pos[i] = i;
        room[i] = i;
        id[i] = i;
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            pos[a] = id[b];
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            if (a == b) continue;
            int id_a = id[a];
            int id_b = id[b];
            swap(id[a], id[b]);
            room[id_a] = b;
            room[id_b] = a;
        } else if (op == 3) {
            int a;
            cin >> a;
            cout << room[pos[a]] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
