#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'
constexpr int mod = 19260817;

int main() {
    i32 a;
    cin >> a;
    bool p1 = (a % 2 == 0);
    bool p2 = (a > 4 && a < 16);
    cout << ((p1 && p2) ? "1" : "0") << " ";
    cout << ((p1 || p2) ? "1" : "0") << " ";
    cout << ((p1 && !p2) || (p2 && !p1) ? "1" : "0") << " ";
    cout << ((!p1 && !p2) ? "1" : "0") << endl;
    return 0;
}
