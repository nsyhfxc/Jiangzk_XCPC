#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<int> upper(26, 0), lower(26, 0);
    for (char c: str) {
        if (isupper(c)) upper[c - 'A']++;
        else lower[c - 'a']++;
    }
    int cnt = 0;
    vector<int> rem;
    for (int i = 0; i < 26; i++) {
        int com = min(upper[i], lower[i]);
        cnt += com;
        int rems = max(upper[i], lower[i]) - com;
        if (rems > 0) {
            rem.push_back(rems);
        }
    }
    for (int rem: rem) {
        if (k <= 0) break;
        int can = rem / 2;
        int use = min(k, can);
        cnt += use;
        k -= use;
    }

    cout << cnt << endl;

    return 0;
}
