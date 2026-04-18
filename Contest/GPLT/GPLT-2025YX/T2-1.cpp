#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector arr(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = n - 1; i >= -(n - 1); --i) {
        int mnr = max(1, 1 - i);
        int mxr = min(n, n - i);
        int line = (n - 1) - i + 1;
        if (line % 2 == 0) {
            for (int j = mnr; j <= mxr; ++j) {
                cout << arr[j][j + i];
            }
        } else {
            for (int j = mxr; j >= mnr; --j) {
                cout << arr[j][j + i];
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
