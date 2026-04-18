#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<string, size_t> > arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        arr[i].first = name;
        mp.clear();
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int index;
            cin >> index;
            mp[index]++;
        }
        arr[i].second = mp.size();
    }
    struct cmp {
        bool operator()(const pair<string, size_t> &a, const pair<string, size_t> &b) const {
            return a.second > b.second;
        }
    };
    sort(arr.begin(), arr.end(), cmp());
    bool flag = false;
    for (int i = 0; i < 3; i++) {
        cout << (flag ? " " : "") << arr[i].first;
        flag = true;
    }
    if (arr.size() < 3) {
        for (int i = 1; i <= 3 - arr.size(); i++) {
            cout << " -";
        }
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
