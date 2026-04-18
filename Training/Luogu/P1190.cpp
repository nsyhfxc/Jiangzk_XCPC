#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int n, m, w[MAXN];
int s[MAXN];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int t = 1;
        for (int j = 2; j <= m; j++) {
            if (s[t] > s[j]) {
                t = j;
            }
        }
        s[t] += w[i];
    }
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        mx = max(mx, s[i]);
    }
    cout << mx << endl;
    return 0;
}
