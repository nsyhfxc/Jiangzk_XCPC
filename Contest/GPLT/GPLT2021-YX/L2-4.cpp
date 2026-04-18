#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    i32 n, a, b;
    cin >> n >> a >> b;
    auto check = [&](i32 x) {
        const string str = to_string(x);
        if (str.size() != n) {
            return false;
        }
        string temp;
        for (int i = 0; i < str.size(); i++) {
            temp += str[i];
            if (stoll(temp) % (i + 1) != 0) {
                return false;
            }
        }
        return true;
    };
    bool flag = false;
    for (i32 i = a; i <= b; i++) {
        if (check(i)) {
            cout << i << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "No Solution" << endl;
    }
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
