#include<bits/stdc++.h>
using namespace std;

int main() {
    int l = 1, r = 1000000000;
    int res;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        cout << mid << endl;
        cin >> res;
        if (res == 0) {
            return 0;
        }
        if (res == -1) {
            l = mid + 1;
        } else if (res == 1) {
            r = mid - 1;
        }
    }

    return 0;
}
