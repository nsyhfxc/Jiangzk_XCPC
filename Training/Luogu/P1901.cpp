#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
constexpr int MAXN = 1000005;
int h[MAXN], v[MAXN];
i32 sum[MAXN];
int stk[MAXN], top = 0;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        while (top > 0 && h[stk[top]] < h[i]) {
            sum[i] += v[stk[top]];
            top--;
        }
        if (top > 0) {
            sum[stk[top]] += v[i];
        }
        stk[++top] = i;
    }
    i32 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sum[i]);
    }
    cout << ans << endl;

    return 0;
}
