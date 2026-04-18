#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    map<int, vector<int> > mp;//天梯赛分数 PAT分数
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x >= 175) {
            mp[x].push_back(y);
        }
    }
    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        vector<int> pats = it->second;
        sort(pats.begin(), pats.end(), greater<int>());
        int used = 0;
        for (const auto pat: pats) {
            if (pat >= s) {
                cnt++;
            } else if (used < k) {
                used++;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
