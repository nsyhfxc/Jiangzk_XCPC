#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> arr;
    int mx = 0;
    auto work = [](int x) -> int {
        int res = 0;
        while (x > 10) {
            int tmp = 1;
            while (x) {
                tmp *= x % 10;
                x /= 10;
            }
            x = tmp;
            res++;
        }
        return res;
    };
    for (int i = l; i <= r; i++) {
        int cur = work(i);
        if (cur > mx) {
            mx = cur;
            arr.clear();
            arr.emplace_back(i);
        } else if (cur == mx) {
            arr.emplace_back(i);
        }
    }
    cout << mx << endl;
    for (int i = 0; i < (int) arr.size(); i++) {
        cout << arr[i] << " \n"[i == (int) arr.size() - 1];
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
