#include<bits/stdc++.h>
using namespace std;
// 10 pts
int main() {
    int n;
    cin >> n;
    int x;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i % 2 == 0) {
            cnt += x;
        }
    }
    cout << cnt << endl;
}
