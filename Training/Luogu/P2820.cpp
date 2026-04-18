#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) {
        int x, y, m;
        cin >> x >> y >> m;
        mp[x]++;
        mp[y]++;
    }
    for (auto it: mp) {
        cout << it.first << " " << it.second << endl;
    }
}
