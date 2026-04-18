#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    string token;
    vector<string> words;
    while (getline(ss, token, ' ')) {
        words.push_back(token);
    }
    auto check = [&](const string &word)-> bool {
        if (!(word.size() & 1)) {
            return true;
        }
        int yuan = 0;
        for (const auto &c: word) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                yuan++;
            }
        }
        return (yuan & 1);
    };
    vector<string> smartword;
    vector<string> stupidword;
    for (const auto &word: words) {
        if (check(word)) {
            smartword.push_back(word);
            //cout << word << "-> smart;" << endl;
        } else {
            stupidword.push_back(word);
            //cout << word << "-> stupid;" << endl;
        }
    }
    sort(smartword.begin(), smartword.end(), [&](const string &s1, const string &s2)-> bool {
        if (s1.size() != s2.size()) return s1.size() > s2.size();
        return s1 < s2;
    });
    sort(stupidword.begin(), stupidword.end(), [&](const string &s1, const string &s2)-> bool {
        if (s1.size() != s2.size()) return s1.size() > s2.size();
        return s1 < s2;
    });
    cout << smartword.size() << endl << stupidword.size() << endl;
    if (!smartword.empty()) {
        cout << smartword[0] << endl;
    } else cout << "None" << endl;
    if (!stupidword.empty()) {
        cout << stupidword[0] << endl;
    } else cout << "None" << endl;
    return 0;
}
