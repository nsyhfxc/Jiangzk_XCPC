#include<bits/stdc++.h>
constexpr int N = 3e6 + 10;
int n, arr[N], ans[N], stk[N];
using namespace std;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int top = 0;
    for (int i = 1; i <= n; i++) {
        while (top > 0 && arr[stk[top]] < arr[i]) {
            ans[stk[top]] = i;
            top--;
        }
        stk[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
