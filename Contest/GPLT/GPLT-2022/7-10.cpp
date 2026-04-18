#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

struct Times {
    string start;
    string end;

    bool operator<(const Times &other) const {
        return start < other.start;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Times> arr(n);
    for (int i = 0; i < n; ++i) {
        string s, dash, e;
        cin >> s >> dash >> e;
        arr[i] = {s, e};
    }

    sort(arr.begin(), arr.end());

    if (arr[0].start != "00:00:00") {
        cout << "00:00:00 - " << arr[0].start << endl;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i].end < arr[i + 1].start) {
            cout << arr[i].end << " - " << arr[i + 1].start << endl;
        }
    }

    if (arr[n - 1].end != "23:59:59") {
        cout << arr[n - 1].end << " - 23:59:59" << endl;
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
