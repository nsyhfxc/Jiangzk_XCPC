#include<iostream>
#include<cstdio>
using namespace std;
int a[20][20];

int main() {
    int n;
    int now = 2, x = 1, y = 1;
    a[1][1] = 1;
    cin >> n;
    while (now <= n * n) {
        while (y + 1 <= n && a[x][y + 1] == 0) {
            y++;
            a[x][y] = now;
            now++;
        }
        while (x + 1 <= n && a[x + 1][y] == 0) {
            x++;
            a[x][y] = now;
            now++;
        }
        while (y - 1 >= 1 && a[x][y - 1] == 0) {
            y--;
            a[x][y] = now;
            now++;
        }
        while (x - 1 >= 1 && a[x - 1][y] == 0) {
            x--;
            a[x][y] = now;
            now++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", a[i][j]);
        }
        cout << endl;
    }
    return 0;
}
