#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    vector<vector<int>> a(3, vector<int>(3));
    int sum = 0, zx = -1, zy = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                zx = i;
                zy = j;
            } else {
                sum += a[i][j];
            }
        }
    }

    a[zx][zy] = 45 - sum;

    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << a[x][y] << endl;
    }

    vector<int> val(25);
    val[6] = 10000;
    val[7] = 36;
    val[8] = 720;
    val[9] = 360;
    val[10] = 80;
    val[11] = 252;
    val[12] = 108;
    val[13] = 72;
    val[14] = 54;
    val[15] = 180;
    val[16] = 72;
    val[17] = 180;
    val[18] = 119;
    val[19] = 36;
    val[20] = 306;
    val[21] = 1080;
    val[22] = 144;
    val[23] = 1800;
    val[24] = 3600;

    int op;
    cin >> op;

    auto get_sum = [&](int op) -> int {
        int res = 0;
        if (1 <= op && op <= 3) {
            int r = op - 1;
            for (int j = 0; j < 3; j++) res += a[r][j];
        } else if (4 <= op && op <= 6) {
            int c = op - 4;
            for (int i = 0; i < 3; i++) res += a[i][c];
        } else if (op == 7) {
            for (int i = 0; i < 3; i++) res += a[i][i];
        } else {
            for (int i = 0; i < 3; i++) res += a[i][2 - i];
        }
        return res;
    };

    cout << val[get_sum(op)] << endl;
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