#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int pa, pb;
    cin >> pa >> pb;
    int a = 0, b = 0;
    int x;
    for (int i = 1; i <= 3; i++) {
        cin >> x;
        if (x) {
            b++;
        } else a++;
    }
    if ((pa > pb && a) || (pa < pb && a == 3)) {
        cout << "The winner is a: " << pa << " + " << a << endl;
        return;
    }
    if ((pb > pa && b) || (pb < pa && b == 3)) {
        cout << "The winner is b: " << pb << " + " << b << endl;
        return;
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
