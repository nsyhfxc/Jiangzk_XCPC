#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n, g, k;
    int sum = 0;
    cin >> n >> g >> k;
    vector<pair<string, int> > arr;
    for (int i = 0; i < n; ++i) {
        string adr;
        int score;
        cin >> adr >> score;
        if (score >= 60 && score < g) {
            sum += 20;
        } else if (score >= g && score <= 100) {
            sum += 50;
        }
        arr.emplace_back(adr, score);
    }
    sort(arr.begin(), arr.end(), [&](const pair<string, int> &a, const pair<string, int> &b)-> bool {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    cout << sum << endl;
    int rank = 1;
    for (int i = 0; i < arr.size(); ++i) {
        if (i > 0 && arr[i].second < arr[i - 1].second) {
            rank = i + 1;
        }
        if (rank > k) break;
        cout << rank << " " << arr[i].first << " " << arr[i].second << endl;
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
