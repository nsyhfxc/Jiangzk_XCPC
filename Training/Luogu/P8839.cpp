#include<bits/stdc++.h>
using namespace std;

void solve() {
    double t, h, e;
    cin >> t >> h >> e;
    double score = t * 0.2 + h * 0.3 + e * 0.5;
    cout << (int)score << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
