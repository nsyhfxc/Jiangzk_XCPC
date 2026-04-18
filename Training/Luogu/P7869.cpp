#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    getline(cin, s);
    bool flag1 = false;
    bool flag2 = false;
    for (int i = 0;i < s.size() - 1;i++) {
        if (s[i] == '\\' && s[i + 1] == 'r') {
            flag1 = true;
        }else if (s[i] == '\\' && s[i + 1] == 'n') {
            flag2 = true;
        }
    }
    if (flag1 && flag2) {
        cout << "windows" << endl;
    }else if (flag1 && !flag2) {
        cout << "mac" << endl;
    }else if (!flag1 && flag2) {
        cout << "linux" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
