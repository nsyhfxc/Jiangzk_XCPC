#include<bits/stdc++.h>
using namespace std;
// 15 pts
void solve() {
    set<int> seen;
    string str;
    getline(cin, str);
    stringstream ss(str);
    string token;
    while (getline(ss, token, ' ')) {
        int temp = stoi(token);
        if (seen.count(temp)) {
            cout << temp << endl;
            return;
        }
        seen.insert(temp);
    }
    cout << "NONE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }
}
