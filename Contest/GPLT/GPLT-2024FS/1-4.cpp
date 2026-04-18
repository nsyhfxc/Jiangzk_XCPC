#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    map<char, int> mp;
    for (const auto &c: str) {
        mp[c]++;
    }
    int mn = 2e9;
    int mx = -2e9;
    for (const auto &[x,y]: mp) {
        if (y > mx) {
            mx = y;
        } else if (y < mn) {
            mn = y;
        }
    }
    auto check = [&](int n)-> bool {
        if (n < 2) return false;
        if (n % 2 == 0) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    };
    if (check(mx - mn)) {
        cout << "Magic Code" << endl << mx - mn << endl;
    } else cout << "No Answer" << endl << "0" << endl;
}
