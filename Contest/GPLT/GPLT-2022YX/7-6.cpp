#include<bits/stdc++.h>
using i32 = long long;
#define endl '\n';
using namespace std;

int main() {
    int n;
    i32 s;
    cin >> n >> s;
    vector<i32> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), less<i32>());
    const int mid = n >> 1;
    i32 ans = 0;
    if (arr[mid] < s) {
        for (int i = mid; i < n; ++i) {
            if (arr[i] < s) {
                ans += (s - arr[i]);
            } else break;
        }
    } else if (arr[mid] > s) {
        for (int i = mid; i >= 0; --i) {
            if (arr[i] > s) {
                ans += (arr[i] - s);
            } else break;
        }
    }
    cout << ans << endl;
    return 0;
}
