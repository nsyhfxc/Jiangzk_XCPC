#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int> db;
    while (n--) {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            if (m > 1) {
                db[s]++;
            }
        }
    }
    int q;
    cin >> q;
    bool flag = false;
    while (q--) {
        string s;
        cin >> s;
        if (!db.count(s)) {
            cout << (flag == true ? " " : "") << s;
            flag = true;
            db[s]++;
        }
    }
    if (flag == false) {
        cout << "No one is handsome" << endl;
    }
    return 0;
}
