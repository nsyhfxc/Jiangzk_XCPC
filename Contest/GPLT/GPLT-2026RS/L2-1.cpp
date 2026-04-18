#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    stack<char>op;
    stack<int>nums;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        nums.push(x);
    }
    for(int i = 1; i < n; i++) {
        char c;
        cin >> c;
        op.push(c);
    }
    auto func = [&](const int n1, const int n2, const char opp)->int {
        if(opp == '+') {
            return n1 + n2;
        } else if(opp == '-') {
            return n1 - n2;
        } else if(opp == '*') {
            return n1 * n2;
        } else if(opp == '/') {
            return n1 / n2;
        }
    };
    while(!op.empty()) {
        int n1 = nums.top();
        nums.pop();
        int n2 = nums.top();
        nums.pop();
        char opp = op.top();
        op.pop();
        if(n1 == 0 && opp == '/') {
            cout << "ERROR: " << n2 << "/0" << endl;
            return;
        }
        nums.push(func(n2,n1,opp));
    }
    cout << nums.top() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
