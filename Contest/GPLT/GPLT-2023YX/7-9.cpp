#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

void solve() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    while (n--) {
        string s;
        int index;
        cin >> s >> index;
        str.insert(index, s);
    }
    cout << str << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
