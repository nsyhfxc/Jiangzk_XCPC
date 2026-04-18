#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'
constexpr int mod = 19260817;

int main() {
    i32 x, y;
    cin >> x >> y;
    auto ksm = [&](i32 a, i32 b)-> i32 {
        i32 res = 1;
        a %= mod;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res % mod;
    };
    cout << ksm(x, y) << endl;
    return 0;
}
