#include<bits/stdc++.h>
using namespace std;

struct Carpet {
    int a, b, g, k;
};

int main() {
    int n;
    cin >> n;
    vector<Carpet> carpets(n);
    for (int i = 0; i < n; i++) {
        cin >> carpets[i].a >> carpets[i].b >> carpets[i].g >> carpets[i].k;
    }
    int x, y;
    cin >> x >> y;
    int ans = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (x >= carpets[i].a && x <= carpets[i].a + carpets[i].g &&
            y >= carpets[i].b && y <= carpets[i].b + carpets[i].k) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
