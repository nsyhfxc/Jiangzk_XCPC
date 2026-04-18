#include<bits/stdc++.h>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    auto func = [&](const string &str)-> string {
        string res = "";
        for (int i = 1; i < size(str); i++) {
            if (str[i] % 2 == str[i - 1] % 2) {
                res += max(str[i], str[i - 1]);
            }
        }
        return res;
    };
    string res1 = func(str1);
    string res2 = func(str2);
    if (res1 == res2) {
        cout << res1 << endl;
    }else {
        cout << res1 << endl;
        cout << res2 << endl;
    }
    return 0;
}
