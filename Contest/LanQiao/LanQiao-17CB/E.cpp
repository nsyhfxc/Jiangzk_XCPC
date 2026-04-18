#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'
void solve() {
    i32 n;
    cin >> n;
    string str;
    cin >> str;
    for(int i = 0; i < n / 2; i++) {
        if(str[i] == '?') {
            str[i] = 'L';
        }
    }
    for(int i = n / 2; i < n; i++) {
        if(str[i] == '?') {
            str[i] = 'Q';
        }
    }
    i32 cnt = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(str[i] == 'L' && str[j] == 'Q') {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
