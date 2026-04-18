#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    string s;
    int cnt = 0;
    while (cin >> s) {
        if (s == "End") {
            break;
        }
        if (cnt == 2) {
            cnt = 0;
            cout << s << endl;
        } else {
            cnt++;
            if (s == "ChuiZi") {
                cout << "Bu" << endl;
            } else if (s == "JianDao") {
                cout << "ChuiZi" << endl;
            } else if (s == "Bu") {
                cout << "JianDao" << endl;
            }
        }
    }
    return 0;
}
