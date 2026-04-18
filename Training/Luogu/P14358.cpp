#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> v[i];
    }
    const int &r = v[0];
    sort(v.begin(), v.end(), greater<int>());
    vector arr(m + 1, vector(n + 1, 0));
    int cnt = 1;
    for (int i = 1; i <= m; i++) {
        if (i & 1) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] += cnt;
                cnt++;
            }
        } else {
            for (int j = n; j >= 1; j--) {
                arr[i][j] += cnt;
                cnt++;
            }
        }
    }
    vector<vector<int> > ans(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] = arr[j][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] = v[ans[i][j] - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans[i][j] == r) {
                cout << j << " " << i << endl;
                break;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
