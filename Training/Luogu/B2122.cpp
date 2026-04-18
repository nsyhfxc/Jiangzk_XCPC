#include<bits/stdc++.h>
using namespace std;
int main() {
    string str;
    while (cin >> str) {
        for (auto it = str.rbegin(); it != str.rend(); it++) {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}