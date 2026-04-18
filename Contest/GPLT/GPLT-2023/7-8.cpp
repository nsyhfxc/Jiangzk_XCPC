#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    auto sum_digit = [&](i32 x) -> i32 {
        i32 s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    };

    while (n--) {
        i32 na, nb;
        cin >> na >> nb;

        i32 sa = sum_digit(na);
        i32 sb = sum_digit(nb);

        bool fa = (na % sb == 0); // A 是否满足“是爹”条件
        bool fb = (nb % sa == 0); // B 是否满足“是爹”条件

        char ans;
        if (fa != fb) {
            ans = fa ? 'A' : 'B';
        } else {
            ans = (na > nb) ? 'A' : 'B';
        }

        cout << ans << endl;
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
