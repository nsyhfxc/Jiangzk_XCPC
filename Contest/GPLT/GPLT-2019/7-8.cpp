#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    cin.ignore();

    auto is_punc = [&](char c) -> bool {
        return ispunct(static_cast<unsigned char>(c));
    };

    auto is_sep = [&](char c) -> bool {
        return c == ' ' || is_punc(c);
    };

    auto normalize = [&](const string &line) -> string {
        string s;
        for (char c: line) {
            if (c == ' ') {
                if (s.empty() || s.back() == ' ') continue;
                s.push_back(' ');
            } else {
                if (is_punc(c) && !s.empty() && s.back() == ' ') s.pop_back();
                s.push_back(c);
            }
        }
        while (!s.empty() && s.back() == ' ') s.pop_back();
        return s;
    };

    auto to_lower_keep_I = [&](string s) -> string {
        for (char &c: s) {
            if ('A' <= c && c <= 'Z' && c != 'I') {
                c = c - 'A' + 'a';
            }
        }
        return s;
    };

    auto reply = [&](string line) -> string {
        string s = normalize(line);
        s = to_lower_keep_I(s);

        string ans;
        int m = s.size();

        for (int i = 0; i < m;) {
            if (s[i] == ' ') {
                ans.push_back(' ');
                i++;
            } else if (is_punc(s[i])) {
                ans.push_back(s[i] == '?' ? '!' : s[i]);
                i++;
            } else {
                int j = i;
                while (j < m && !is_sep(s[j])) j++;
                string w = s.substr(i, j - i);
                //i,j之间的所有内容
                if ((w == "can" || w == "could") && j < m && s[j] == ' ') {
                    int k = j + 1, l = k;
                    while (l < m && !is_sep(s[l])) l++;
                    string nxt = s.substr(k, l - k);
                    if (nxt == "you") {
                        ans += (w == "can" ? "I can" : "I could");
                        i = l;
                        continue;
                    }
                }

                if (w == "I" || w == "me") ans += "you";
                else ans += w;

                i = j;
            }
        }

        return ans;
    };

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        cout << line << endl;
        cout << "AI: " << reply(line) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
