#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    char c;
    cin >> c;
    int n;
    cin >> n;
    string res;
    cin.ignore();
    vector<string> arr(n + 1, "");
    for (int i = 1; i <= n; i++) {
        getline(cin, arr[i]);
        res += arr[i];
    }
    string cm;
    for (int i = n; i >= 1; i--) {
        for (int j = n - 1; j >= 0; j--) {
            cm += arr[i][j];
            if (arr[i][j] != ' ') {
                arr[i][j] = c;
            }
        }
    }
    if (cm == res) {
        cout << "bu yong dao le" << endl;
    }
    for (int i = n; i >= 1; i--) {
        string ans;
        for (int j = n - 1; j >= 0; j--) {
            ans += arr[i][j];
        }
        cout << ans << endl;
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
}
