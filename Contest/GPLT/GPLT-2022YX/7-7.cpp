#include<bits/stdc++.h>
using namespace std;

int charToint(char c) {
    if (isdigit(c)) return c - '0';
    return toupper(c) - 'A' + 10;
}

char intTochar(int v) {
    if (v < 10) return v + '0';
    return v - 10 + 'A';
}

string add(int n, string s1, string s2) {
    string res = "";
    int i = s1.size() - 1, j = s2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int val1 = (i >= 0) ? charToint(s1[i--]) : 0;
        int val2 = (j >= 0) ? charToint(s2[j--]) : 0;
        int sum = val1 + val2 + carry;
        res += intTochar(sum % n);
        carry = sum / n;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    cout << add(n, s1, s2) << endl;
    return 0;
}
