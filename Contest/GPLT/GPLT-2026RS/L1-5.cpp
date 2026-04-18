#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    int year, n;
    cin >> year >> n;
    for (int i = year; i <= 9999; i++) {
        string temp = to_string(i);
        while (temp.size() < 4) {
            temp = "0" + temp;
        }
        set<char> st;
        for (const auto &c: temp) {
            st.insert(c);
        }
        if (int(st.size()) == n) {
            cout << i - year << " ";
            cout << temp << endl;
            return;
        }
    }
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
