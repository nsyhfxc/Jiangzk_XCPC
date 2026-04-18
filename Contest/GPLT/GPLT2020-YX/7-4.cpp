#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    int res[5][5] = {
        {2, 0, 1, 1, 0}, // 剪刀
        {1, 2, 0, 1, 0}, // 石头
        {0, 1, 2, 0, 1}, // 布
        {0, 0, 1, 2, 1}, // 中指
        {1, 1, 0, 0, 2} // 小指
    };
    int A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        int r = res[a[i]][b[i]];
        if (r == 2) {
            A++;
            B++;
        } else if (r == 1) {
            A++;
        } else {
            B++;
        }
    }

    cout << A << "\n";
}
