#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    while (n--) {
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << mp["i"] + mp["int"] + mp["integer"] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}