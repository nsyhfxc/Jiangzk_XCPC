#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    vector<int> init(6);
    for (int i = 0; i < 6; i++) {
        cin >> init[i];
    }
    int n;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        int val = 6;
        int cnt = 0;
        while (cnt < n) {
            if (val != init[i]) {
                cnt++;
                if (cnt == n) break;
            }
            val--;
        }
        cout << val << (i == 5 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}