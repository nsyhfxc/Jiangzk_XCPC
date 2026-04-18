#include<bits/stdc++.h>
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    i32 cnt = 0;
    vector<pair<i32, i32> > v;
    while (n--) {
        i32 a, b, c;
        i32 d, e, f;
        scanf("%lld:%lld:%lld", &a, &b, &c);
        scanf("%lld:%lld:%lld", &d, &e, &f);
        i32 l = a * 3600 + b * 60 + c;
        i32 r = d * 3600 + e * 60 + f;
        v.emplace_back(l, r);
    }
    sort(v.begin(), v.end());
    int num = 24 * 3600;
    vector<int> diff(num + 1, 0);
    for (const auto &[start,end]: v) {
        diff[start]++;
        diff[end + 1]--;
    }
    i32 mx = 0;
    for (int i = 0; i <= num; i++) {
        cnt += diff[i];
        mx = max(mx, cnt);
    }
    cout << mx << "\n";
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    i32 t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
