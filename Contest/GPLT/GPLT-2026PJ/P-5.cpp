#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c, times = 1, cnt = 0, last;
    scanf("%d %d", &a, &b);
    while (~scanf("%d", &c)) {
        cnt++;
        times = (cnt - 1) * 2 + 1;
        if (times >= 3 * 60 * 60) {
            times -= 2;
            printf("%d Wrong Answer %02d:%02d:%02d", last, times / 3600, (times % 3600) / 60, times % 60);
            break;
        }
        if (c == a + b) {
            printf("%d Accepted %02d:%02d:%02d", c, times / 3600, (times % 3600) / 60, times % 60);
            break;
        }
        last = c;
    }
    return 0;
}
