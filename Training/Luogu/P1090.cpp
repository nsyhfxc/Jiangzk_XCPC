#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>,greater<ll> > pq;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pq.push(x);
    }
    ll res = 0;
    while (pq.size() > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ll temp = a + b;
        pq.push(temp);
        res += temp;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
