#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<string, int> db[1001];
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        while (l--) {
            string s;
            cin >> s;
            db[i][s]++;
        }
    }
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++) {
            if (db[i].count(s)) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
