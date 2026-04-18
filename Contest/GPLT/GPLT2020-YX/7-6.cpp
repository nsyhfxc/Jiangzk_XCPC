#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'
constexpr int mod = 19260817;

int main() {
    map<char, int> mp;
    string str;
    getline(cin, str);
    for (const auto &c : str) {
        mp[c]++;
    }
    char c;
    cin >> c;
    cout << mp[c] << endl;
    return 0;
}
