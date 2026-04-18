#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length();) {
        if (str[i] == '6') {
            int j = i;
            while (j < str.length() && str[j] == '6') {
                j++;
            }
            //it is so 666 really 6666 what else can I say 6666666666
            const int cnt = j - i; //连续6的个数
            if (cnt > 9) {
                cout << "27";
            } else if (cnt > 3) {
                cout << "9";
            } else {
                for (int k = 0; k < cnt; k++) cout << '6';
            }
            i = j;
        } else {
            cout << str[i];
            i++;
        }
    }
    cout << endl;
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
