#include<bits/stdc++.h>
using namespace std;
constexpr int N = 70;
int n, len, cnt;
int a[N], used[N];

void dfs(const int &u, const int &cur, const int &start) {
    if (u > cnt) {
        cout << len << endl;
        exit(0);
    }
    if (cur == len) {
        dfs(u + 1, 0, 1);
        return;
    }
    for (int i = start; i <= n; i++) {
        if (used[i] || cur + a[i] > len) continue;
        used[i] = 1;
        dfs(u, cur + a[i], i + 1);
        used[i] = 0;

        if (cur == 0) return;
        if (cur + a[i] == len) return;
        while (i < n && a[i] == a[i + 1])i++;
    }
}

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)cin >> a[i], sum += a[i];
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    for (len = a[1]; len <= sum; len++) {
        if (sum % len) continue;
        cnt = sum / len;
        dfs(1, 0, 1);
    }
}
