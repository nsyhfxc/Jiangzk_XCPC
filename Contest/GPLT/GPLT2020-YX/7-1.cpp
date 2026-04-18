#include<bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cin >> c;
    char res;
    if (islower(c)) {
        res = toupper(c);
    } else {
        res = tolower(c);
    }
    cout << res;
    return 0;
}
