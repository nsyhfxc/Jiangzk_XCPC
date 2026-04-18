#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    string str;
    cin >> str;
    if (str.size() == 6) {
        cout << str.substr(0, 4) << "-" << str.substr(4, 2) << endl;
    }
    if (str.size() == 4) {
        int year = stoi(str.substr(0, 2));
        if (year < 22) {
            str = "20" + str;
            cout << str.substr(0, 4) << "-" << str.substr(4, 2) << endl;
        } else {
            str = "19" + str;
            cout << str.substr(0, 4) << "-" << str.substr(4, 2) << endl;
        }
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
    return 0;
}
