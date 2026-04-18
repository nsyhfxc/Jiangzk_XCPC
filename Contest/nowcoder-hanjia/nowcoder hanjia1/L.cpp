#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n % 10 == 0) {
        cout << "1" << endl;
    }else if (n % 2 == 0) {
        cout << "5" << endl;
    }else if (n % 5 == 0) {
        cout << "2" << endl;
    }else cout << "10" << endl;
    return 0;
}