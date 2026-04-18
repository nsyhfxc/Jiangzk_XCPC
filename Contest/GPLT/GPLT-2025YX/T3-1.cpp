#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e9;
using i32 = long long;
#define endl '\n'
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void solve() {
    int h, w;
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--;
    cw--;
    dh--;
    dw--;
    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }
    vector dist(h, vector(w, MAXN));
    deque<pair<int, int> > dq;

    dist[ch][cw] = 0;
    dq.push_front({ch, cw});

    while (!dq.empty()) {
        const pair<int, int> &curr = dq.front();
        dq.pop_front();
        int r = curr.first;
        int c = curr.second;
        if (r == dh && c == dw) {
            cout << dist[r][c] << endl;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] == '.') {
                if (dist[nr][nc] > dist[r][c]) {
                    dist[nr][nc] = dist[r][c];
                    dq.push_front({nr, nc});
                }
            }
        }
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                int nr = r + i;
                int nc = c + j;
                if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] == '.') {
                    if (dist[nr][nc] > dist[r][c] + 1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        dq.push_back({nr, nc});
                    }
                }
            }
        }
    }

    if (dist[dh][dw] == MAXN) {
        cout << -1 << endl;
    } else {
        cout << dist[dh][dw] << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
