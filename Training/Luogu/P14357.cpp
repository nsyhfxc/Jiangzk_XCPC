#include<bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin >> a;
    multiset<char,greater<char>>s;
    for (auto c : a) {
        if (c >= '0' && c <= '9') {
            s.insert(c);
        }
    }
    for (auto x : s) {
        cout << x;
    }
    return 0;
}