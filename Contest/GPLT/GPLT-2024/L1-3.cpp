#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int a, b;
    cin >> a >> b;
    if (b == 1) {
        cout << "-" << endl;
        cout << (a == 1 ? "move" : "stop") << endl;
    } else {
        if (a == 0) cout << "biii" << endl << "stop" << endl;
        else if (a == 1) cout << "dudu" << endl << "move" << endl;
        else cout << "-" << endl << "stop" << endl;
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