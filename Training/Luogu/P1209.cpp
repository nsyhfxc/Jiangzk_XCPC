#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, s, c;
    cin >> m >> s >> c;
    vector<int> cow(c);
    for (int i = 0; i < c; i++) {
        cin >> cow[i];
    }
    sort(cow.begin(), cow.end());
    int ans = 0;
    ans += c;
    if (c > m) {

    }
}
