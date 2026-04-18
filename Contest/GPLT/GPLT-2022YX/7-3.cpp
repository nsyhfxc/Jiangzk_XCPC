#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] > m) {
            cnt++;
            sum = arr[i];
        }else {
            sum += arr[i];
        }
    }
    if (sum > 0) cnt++;
    cout << cnt << endl;
}
