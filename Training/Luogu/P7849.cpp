#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
const i32 P = 1e9 + 7;

int ask_compare(int x, int y) {
    cout << "> " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

i32 ask_value(int x) {
    cout << "? " << x << endl;
    i32 res;
    cin >> res;
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    if (n == 1) {
        cout << "! 0" << endl;
        return 0;
    }

    int mx_idx = 1;
    int mi_idx = 1;
    for (int i = 2; i <= n; ++i) {
        if (ask_compare(i, mx_idx)) {
            mx_idx = i;
        }
        if (ask_compare(mi_idx, i)) {
            mi_idx = i;
        }
    }
    i32 val_max = ask_value(mx_idx);
    i32 val_min = ask_value(mi_idx);
    i32 diff;
    if (val_max >= val_min) {
        diff = val_max - val_min;
    } else {
        diff = val_max - val_min + P;
    }
    i32 d = diff / (n - 1);
    cout << "! " << d << endl;

    return 0;
}
