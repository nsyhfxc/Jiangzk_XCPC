#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    i32 n;
    cin >> n;
    vector<i32> v(n);
    map<int, vector<int>, greater<int> > hs;
    for (i32 i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (i32 i = 0; i < n; i++)
        for (i32 j = 1; j <= sqrt(v[i]); j++)
            if (v[i] % j == 0) {
                hs[j].emplace_back(v[i]);
                if (v[i] / j != j) hs[v[i] / j].emplace_back(v[i]);
            }
    for (auto e: hs) {
        if (e.second.size() >= 3) {
            for (int i = 0; i < 3; i++)
                cout << e.second[i] << " ";
            break;
        }
    }
    return 0;
}
