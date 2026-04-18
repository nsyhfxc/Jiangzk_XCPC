#include<bits/stdc++.h>
using namespace std;
int n, d;

struct Cake {
    double first;
    double second;
    double price;
};

struct cmp {
    bool operator()(const Cake &A, const Cake &B) const {
        return A.price > B.price;
    }
};

void solve() {
    cin >> n >> d;
    vector<Cake> mc(n);
    for (int i = 0; i < n; i++) {
        cin >> mc[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> mc[i].second;
    }
    for (int i = 0; i < n; i++) {
        mc[i].price = mc[i].second / mc[i].first;
    }
    sort(mc.begin(), mc.end(), cmp());
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (mc[i].first <= d) {
            ans += mc[i].second;
            d -= static_cast<int>(mc[i].first);
        }
        else if (mc[i].second > d) {
            ans += mc[i].price * d;
            d = 0;
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
