#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n,a,s = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        s = gcd(s,abs(a));
    }
    cout << s << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}