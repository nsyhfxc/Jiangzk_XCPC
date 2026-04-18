#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<string, int> > arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        sum += arr[i].second;
    }
    int aver = sum / 2 / n;
    cout << aver << " ";
    for (int i = 0; i < n; i++) {
        const int temp = abs(arr[i].second - aver);
        arr[i].second = temp;
    }
    sort(arr.begin(), arr.end(), [&](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second < b.second;
    });
    cout << arr.front().first << endl;
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
