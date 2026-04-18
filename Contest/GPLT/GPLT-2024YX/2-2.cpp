#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string dna;
    int k;
    cin >> dna >> k;
    int n = dna.length();
    if (n < k) {
        cout << 0 << endl;
        return 0;
    }
    unordered_map<string, int> cnts;
    int mx = 0;
    for (int i = 0; i <= n - k; ++i) {
        string sub = dna.substr(i, k);
        cnts[sub]++;
        if (cnts[sub] > mx) {
            mx = cnts[sub];
        }
    }
    cout << mx << endl;
    return 0;
}
