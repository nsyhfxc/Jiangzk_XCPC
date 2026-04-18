#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int x;
        cin >> x;
        cnt += (x != 1 ? 1 : 0);
    }
    cout << cnt << endl;
    return 0;
}