#include<bits/stdc++.h>
using namespace std;
using i32 = unsigned long long;
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    queue<string> que;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        if (s.find("qiandao") == string::npos && s.find("easy") == string::npos) {
            que.push(s);
        }
    }
    while (m-- && !que.empty()) {
        que.pop();
    }
    if (!que.empty()) cout << que.front() << endl;
    else cout << "Wo AK le" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
