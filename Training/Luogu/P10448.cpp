#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    vector<int> path;
    cin >> n >> m;
    function<void(int, int)> dfs = [&](int step, int start)-> void {
        if (path.size() == m) {
            for (int i = 0; i < m; ++i) {
                cout << path[i] << (i == m - 1 ? "" : " ");
            }
            cout << endl;
            return;
        }

        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            dfs(step + 1, i + 1);
            path.pop_back();
        }
    };
    dfs(1, 1);

    return 0;
}
