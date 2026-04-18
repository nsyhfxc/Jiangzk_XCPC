#include<bits/stdc++.h>
using namespace std;

void solve() {
    string line;
    getline(cin, line);
    size_t pos1 = line.find(',');
    size_t pos2 = line.find('.');
    bool cond1 = (pos1 >= 3 && line.substr(pos1 - 3, 3) == "ong");
    bool cond2 = (pos2 >= 3 && line.substr(pos2 - 3, 3) == "ong");
    if (cond1 && cond2) {
        stringstream ss(line);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        for (int i = 0; i < words.size() - 3; ++i) {
            cout << words[i] << (i == words.size() - 4 ? "" : " ");
        }
        cout << " qiao ben zhong." << endl;
    } else {
        cout << "Skipped" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 必须跳过 n 之后的换行符，否则 getline 会读到空行
    while (n--) {
        solve();
    }
    return 0;
}
