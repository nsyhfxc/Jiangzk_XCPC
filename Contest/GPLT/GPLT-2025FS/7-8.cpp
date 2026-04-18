#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << (2 * i + 1) << (i == n - 1 && n == 1 ? "" : " ");
    }
    for (int i = n - 1; i >= 1; --i) {
        cout << (2 * i) << (i == 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
