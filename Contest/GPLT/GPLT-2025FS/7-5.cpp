#include <bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i32> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    i32 x = 0; //构造的异或因子
    i32 mn = 0; //最终最小的序列和
    for (int k = 0; k <= 30; k++) {//确定x的值
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if ((arr[i] >> k) & 1) { //第k位是不是1
                cnt1++;
            }
        }
        int cnt0 = n - cnt1;
        if (cnt1 >= cnt0) {
            x =  x | (1LL << k);
            mn += static_cast<i32>(cnt0) * (1LL << k);
        } else {
            mn += static_cast<i32>(cnt1) * (1LL << k);
        }
    }

    cout << x << endl;
    cout << mn << endl;

    return 0;
}
