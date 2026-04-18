#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'

void solve() {
    string str;
    cin >> str;
    if (str.size() == 4) {
        if ((str[0] - '0') * 10 + str[1] - '0' >= 22) {
            cout << "19" << str[0] << str[1] << "-" << str[2] << str[3] << endl;
        } else {
            cout << "20" << str[0] << str[1] << "-" << str[2] << str[3] << endl;
        }
    } else {
        for (int i = 0; i < str.size(); i++) {
            cout << str[i];
            if (i == 3) {
                cout << "-";
            }
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
}
