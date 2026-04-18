#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'

void solve() {
    int n,m;
    cin >> n >> m;
    while (m--) {
        int cnt = 1;
        string str;
        cin >> str;
        for (int i = 0 ; i < n ; i++) {
            if (str[i] == 'y') {
                cnt = 2 * cnt;
            }else {
                cnt = 2 * cnt + 1;
            }
        }
        cout << cnt - (int)pow(2,n) + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
