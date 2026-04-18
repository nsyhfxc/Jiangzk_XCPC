#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int cnt0 = 0;
        int cnt1 = 0;
        for (int j = i; j < n; j++) {
            if (a[j] == 0) cnt0++;
            else cnt1++;
            if (cnt0 == cnt1) {
                mx = max(mx, j - i + 1);
            }
        }
    }
    cout << mx << endl;
    return 0;
}
