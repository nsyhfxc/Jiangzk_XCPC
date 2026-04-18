#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'
set<i32> dbnums;
set<i32> trnums;
// 20pts 满分
void solve() {
    i32 z;
    cin >> z;
    bool db = false;
    bool tr = false;
    if (dbnums.count(z / 2) && z % 2 == 0) {
        db = true;
    }
    if (trnums.count(z / 3) && z % 3 == 0) {
        tr = true;
    }
    if (db == true && tr == false) {
        cout << z << " is a double flower" << endl;
        return;
    }
    if (tr == true) {
        cout << z << " is a triple flower" << endl;
        return;
    }
    cout << z << " is " << z << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (i32 i = 1; i * i <= (2e9); i++) {
        dbnums.insert(i * i);
    }
    for (i32 i = 1; i * i * i <= (2e9 + 1000); i++) {
        trnums.insert(i * i * i);
    }
    while (t--) {
        solve();
    }
}
