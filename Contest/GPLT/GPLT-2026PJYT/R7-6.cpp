#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int l1 = str[0] + str[1] + str[2];
        int l2 = str[3] + str[4] + str[5];
        if (l1 == l2) {
            cout << "You are lucky!" << endl;
        } else cout << "Wish you good luck." << endl;
    }
    return 0;
}
