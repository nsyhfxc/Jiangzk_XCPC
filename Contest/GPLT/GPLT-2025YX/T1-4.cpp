#include<bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    i32 k, n, w;
    cin >> k >> n >> w;
    cout << max((1 + w) * w * 3 / 2 - n, 0LL) << endl;
    return 0;
}
