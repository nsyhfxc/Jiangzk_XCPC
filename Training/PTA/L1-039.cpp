#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'

void solve() {
    int n;
    string str;
    cin >> n;
    cin.ignore();
    getline(cin, str);
    while (str.size() % n != 0) {
        str.push_back(' ');
    }
    for (int i = 1; i <= n; i++) {
        for (int j = static_cast<int>(str.size()) + i - 1 - n; j >= 0; j -= n) {
            cout << str[j];
        }
        cout << endl;
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
