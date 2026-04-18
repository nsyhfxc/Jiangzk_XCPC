#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int ban, acc, age1, age2;
    cin >> ban >> acc >> age1 >> age2;
    bool can1 = false, can2 = false;
    if (age1 >= ban) can1 = true;
    if (age2 >= ban) can2 = true;
    if (age1 >= acc && age2 < ban) can2 = true;
    if (age2 >= acc && age1 < ban) can1 = true;
    cout << age1 << '-' << (can1 ? 'Y' : 'N') << ' ' << age2 << '-' << (can2 ? 'Y' : 'N') << endl;

    if (can1 && can2) {
        if (age1 >= ban && age2 >= ban) {
            cout << "huan ying ru guan" << endl;
        } else if (age1 >= acc) {
            cout << "qing 1 zhao gu hao 2" << endl;
        } else {
            cout << "qing 2 zhao gu hao 1" << endl;
        }
    } else if (!can1 && !can2) {
        cout << "zhang da zai lai ba" << endl;
    } else {
        if (can1) cout << "1: huan ying ru guan" << endl;
        else cout << "2: huan ying ru guan" << endl;
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