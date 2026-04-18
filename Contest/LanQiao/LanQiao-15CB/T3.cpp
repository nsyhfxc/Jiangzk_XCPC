#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 n;
    cin >> n;
    auto func = [&](i32 x)-> bool {
        int cnt = 1;
        while (x) {
            int tmp = x % 10;
            if (cnt % 2 == 0 && tmp % 2 == 1) {
                return false;
            }
            if (cnt % 2 == 1 && tmp % 2 == 0) {
                return false;
            }
            cnt++;
            x /= 10;
        }
        return true;
    };
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (func(i)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
