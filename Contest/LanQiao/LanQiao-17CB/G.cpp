#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'
struct Temp {
    i32 a, b;
};
void solve() {
    int n;
    cin >> n;
    vector<Temp>arr(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].a;
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].b;
    }
    map<i32, i32>mp;
    for(int i = 1; i <= n; i++) {
        i32 diff = arr[i].b - arr[i].a;
        mp[diff]++;
    }
    i32 mx = -2e9;
    for(const auto & it : mp) {
        if(it.second > mx) {
            mx = it.second;
        }
    }
    cout << mx << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
