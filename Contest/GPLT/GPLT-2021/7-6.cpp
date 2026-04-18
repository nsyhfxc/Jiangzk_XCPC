#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        string str;
        getline(cin, str);
        if (str.find("qiandao") == string::npos && str.find("easy") == string::npos) {
            cnt++;
        }
        if (cnt > m) {
            cout << str << endl;
            return;
        }
    }
    cout << "Wo AK le" << endl;
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
