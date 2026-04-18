#include<bits/stdc++.h>
#define endl '\n'
#define ll int
using namespace std;

struct Coins {
    double value;
    double weight;
    double coin;
};

bool cmp(const Coins &a, const Coins &b) {
    return a.coin > b.coin;
}

void solve() {
    int n;
    double t;
    cin >> n >> t;
    vector<Coins> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].weight >> arr[i].value;
        arr[i].coin = arr[i].value / arr[i].weight;
    }
    sort(arr.begin(), arr.end(), cmp);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        //cout << arr[i].weight << ' ' << arr[i].value << endl;
        if (arr[i].weight <= t) {
            t -= arr[i].weight;
            ans += arr[i].value;
        }else if (arr[i].weight > t) {
            ans += arr[i].coin * t;
            t = 0;
            break;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
