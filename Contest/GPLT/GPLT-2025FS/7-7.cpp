#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

void solve() {
    int n;//序列长度
    i32 x, y;//上下界
    cin >> n >> x >> y;
    vector<i32> a(n);
    i32 Sum = 0;//所有元素的累加和
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        Sum += a[i];//读取一个就加一个
    }
    sort(a.begin(), a.end());//二分查找，必须有序
    i32 L = Sum - y;
    i32 R = Sum - x;
    i32 ans = 0;
    for (int i = 0; i < n; ++i) {
        i32 mn = L - a[i];//a[i] + a[j] 的范围是[L,R];
        i32 mx = R - a[i];
        auto start = lower_bound(a.begin() + i + 1, a.end(), mn);
        //找的是第一个大于等于mn的位置
        auto end = upper_bound(a.begin() + i + 1, a.end(), mx);
//找的是第一个大于mx的位置

        ans += distance(start, end);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
