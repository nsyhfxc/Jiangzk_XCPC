#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    while (n--) {
        system("MKcode.exe > data.txt");
        system("BFcode.exe < data.txt > BF.txt");
        system("ACcode.exe < data.txt > AC.txt");

        if (system("fc AC.txt BF.txt")) {
            cout << "WA!" << endl;
            system("type data.txt");
            system("type BF.txt");
            system("type AC.txt");
            break;
        }
    }
    cout << "This Code is AC!" << endl;
}
