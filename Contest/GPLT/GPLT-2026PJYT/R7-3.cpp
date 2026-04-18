#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int a = max({0,x,y});
    int b = max({0,x+y});
    cout << a << " " << b << endl;
    if (x < 0 && y < 0) {
        cout << "-_-" << endl;
    }else if (a < b) {
        cout << "^_^" << endl;
    }else cout << "T_T" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}