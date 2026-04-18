#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 100005;
int a[N], b[N], id[N];
priority_queue<pair<int, int>,
    vector<pair<int, int> >,
    greater<pair<int, int> > > q;

auto solve() -> void {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        id[i] = 1;
        q.emplace(a[1] + b[i], i);
    }
    while (n--) {
        cout << q.top().first << " ";
        int i = q.top().second;
        q.pop();
        q.emplace(a[++id[i]] + b[i], i);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
