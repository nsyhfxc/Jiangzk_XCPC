#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;
    while (n--) {
        int x;
        cin >> x;
        if (x > y) {
            cout << "da le" << endl;
        } else if (x < y) {
            cout << "xiao le" << endl;
        } else break;
    }
    return 0;
}
