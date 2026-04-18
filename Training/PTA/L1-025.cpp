#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool Num(char ch) {
    return !isdigit(ch);
}

int main() {
    int addkey = 0; //判断是否能求和
    string A, B;
    cin >> A;
    getchar(); //清除空格
    getline(cin, B);
    if (count_if(A.begin(), A.end(), Num) == 0 && stoi(A) <= 1000 && stoi(A) >= 1)
        cout << A;
    else {
        cout << "?";
        addkey = 1;
    }
    cout << " + ";
    if (count_if(B.begin(), B.end(), Num) == 0 && stoi(B) <= 1000 && stoi(B) >= 1)
        cout << B;
    else {
        cout << "?";
        addkey = 1;
    }
    cout << " = ";
    if (addkey)
        cout << "?";
    else
        cout << stoi(A) + stoi(B);
    return 0;
}
