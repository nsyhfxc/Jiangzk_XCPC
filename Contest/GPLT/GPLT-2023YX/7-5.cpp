#include<bits/stdc++.h>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    vector<int> diff(l + 1, 0);
    for (int i = 1; i <= m; i++) {
        int start, end;
        cin >> start >> end;
        diff[start]--;
        diff[end + 1]++;
    }
    vector<int> sum(l + 1, 0);
    sum[0] = diff[0];
    for (int i = 1; i <= l; i++) {
        sum[i] = sum[i - 1] + diff[i];
    }
    int cnt = 0;
    for (int i = 0; i <= l; i++) {
        if (!sum[i]) cnt++;
    }
    cout << cnt << endl;
}
