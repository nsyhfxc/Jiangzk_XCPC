#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    int mx = -2e9, idx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] > mx) {
            mx = arr[i];
            idx = i;
        }
    }
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = i + 1;j <= n;j++) {
            if (arr[j] > arr[i]) {
                cnt++;
            }
        }
        cout << cnt << " ";
    }
    cout << "0 " << endl;
    cout << idx << endl;
    return 0;
}
