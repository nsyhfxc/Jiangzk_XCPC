#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string sch, word;
    cin >> sch >> word;
    map<char, bool> tgt;
    int needs = 0;
    for (char c: word) {
        if (!tgt[c]) {
            tgt[c] = true;
            needs++;
        }
    }
    int mn = n + 1;
    for (int i = 0; i < n; i++) {
        map<char, bool> fd;
        int cnt = 0;
        for (int j = i; j < n; j++) {
            char c = sch[j];
            if (tgt[c] && !fd[c]) {
                fd[c] = true;
                cnt++;
            }
            if (cnt == needs) {
                mn = min(mn, j - i + 1);
                break;
            }
        }
    }
    cout << mn << endl;

    return 0;
}
