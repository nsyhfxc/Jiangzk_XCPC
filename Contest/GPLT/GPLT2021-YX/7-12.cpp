#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vtuber;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto it = find(vtuber.begin(), vtuber.end(), x);
        if (it == vtuber.end()) {
            cnt++;
            while (vtuber.size() >= m) {
                vtuber.erase(vtuber.begin());
            }
            vtuber.push_back(x);

        }
    }
    cout << cnt << endl;
    return 0;
}
