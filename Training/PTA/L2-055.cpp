#include<bits/stdc++.h>
using namespace std;
constexpr int N = 86401;
int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        a[hh * 3600 + mm * 60 + ss]++;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        a[hh * 3600 + mm * 60 + ss + 1]--;
    }
    int cnt = 0;
    b[0] = a[0];
    cnt = max(cnt, b[0]);
    for (int i = 1; i <= 86400; i++) {
        b[i] = b[i - 1] + a[i];
        cnt = max(cnt, b[i]);
    }
    cout << cnt << endl;
}
