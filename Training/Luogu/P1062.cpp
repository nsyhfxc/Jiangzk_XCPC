#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// 洛谷P1062
void solve() {
    int k, n;
    cin >> k >> n;
    auto trans = [&](int x) {
        //数字转二进制字符串模板
        string temp;
        while (x) {
            temp += (x % 2 ? '1' : '0');
            x /= 2;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    };
    string s = trans(n);
    ll ans = 0;
    for (auto c: s) {
        ans = (ans * k) + (c - '0');
        //k进制转10进制模板
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
