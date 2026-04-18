#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 10001;
int a[MAXN][MAXN];
int n, m;

int main() {
    cin >> n >> m;
    int x1, y1, x2, y2;
    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++) {
            a[i][y1]++;
            a[i][y2 + 1]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i][j - 1];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
