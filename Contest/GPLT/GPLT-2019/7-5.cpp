#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    string str;
    cin >> str;
    int pre = 0, last = 0;
    for (int i = 0; i < 3; i++) {
        pre += str[i] - '0';
    }
    for (int i = 3; i < 6; i++) {
        last += str[i] - '0';
    }
    if (pre == last) {
        cout << "You are lucky!" << endl;
    } else {
        cout << "Wish you good luck." << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
