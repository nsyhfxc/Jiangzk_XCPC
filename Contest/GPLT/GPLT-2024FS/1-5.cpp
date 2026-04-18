#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    vector<string> words;
    stringstream ss(str);
    string token;
    while (getline(ss, token, ' ')) {
        if (!token.empty()) {
            words.push_back(token);
        }
    }
    reverse(words.begin(), words.end());
    auto check = [&](const string s) {
        for (const auto &c: s) {
            if (!(c >= '0' && c <= '9')) {
                return false;
            }
        }
        return true;
    };
    for (const auto &word: words) {
        if (check(word)) {
            bool flag = false;
            string res = word;
            reverse(res.begin(), res.end());
            for (const auto &c: res) {
                if (c != '0') flag = true;
                if (flag) cout << c;
            }
        }
        else {
            for (const auto &c: word) {
                if (isupper(c)) {
                    char cl = tolower(c);
                    cout << cl;
                }else {
                    char cu = toupper(c);
                    cout << cu;
                }
            }
        }
        cout << " ";
    }
}
