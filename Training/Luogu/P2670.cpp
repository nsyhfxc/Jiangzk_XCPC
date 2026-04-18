#include<bits/stdc++.h>
using namespace std;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > arr(n + 2, vector<char>(m + 2));
    vector<vector<int> > cnt(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                for (int k = 0; k < 8; k++) {
                    cnt[i + dx[k]][j + dy[k]]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '*') {
                cout << "*";
            } else {
                cout << cnt[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
