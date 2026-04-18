#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'

void solve() {
    string str;
    cin >> str;
    unordered_map<char, i32> db;
    for (const auto &c : str) {
        db[c]++;
    }
    int sum = 0;
    char c = 'a';
    for (int i = 0;i < 26; i++) {
        int x;
        cin >> x;
        sum +=  db[c] * x;
        c++;
    }
    bool flag = false;
    for (char i = 'a';i <= 'z';i++) {
        cout << (flag ? " " : "") << db[i];
        flag = true;
    }
    cout << endl << sum << endl;
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
