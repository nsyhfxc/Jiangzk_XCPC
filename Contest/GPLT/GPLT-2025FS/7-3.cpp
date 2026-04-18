#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    queue<char> Yuan, Fu;
    for (const auto &c: str) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            Yuan.push(c);
        } else Fu.push(c);
    }
    string T;
    while (!Yuan.empty() && !Fu.empty()) {
        const char &y = Yuan.front();
        const char &f = Fu.front();
        if (y < f) {
            T += y;
            Yuan.pop();
        } else {
            T += f;
            Fu.pop();
        }
    }
    if (Yuan.empty() && !Fu.empty()) {
        while (!Fu.empty()) {
            T += Fu.front();
            Fu.pop();
        }
    }
    if (!Yuan.empty() && Fu.empty()) {
        while (!Yuan.empty()) {
            T += Yuan.front();
            Yuan.pop();
        }
    }
    cout << T << endl;
}
