#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    i32 n, T;
    cin >> n >> T;
    stack<i32>left;
    stack<i32>right;
    map<i32, i32>mp;
    i32 sum = 0;
    bool flag = false;
    for(int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        mp[c] = i;
        if(c <= T) {
            cout << (flag ? " " : "") << i;
            flag = true;
        } else {
            left.push(c);
            sum += c;
        }
    }
	if(left.empty()){
		return;
	}
    while(!left.empty() || !right.empty()) {
		T = sum / (int)left.size();
        sum = 0;
        while(!left.empty()) {
            if(left.top() <= T) {
                cout << " " << mp[left.top()];
                left.pop();
            } else {
                right.push(left.top());
                sum += left.top();
                left.pop();
            }
        }
        if(right.empty()) {
            return;
        }
        T = sum / (int)right.size();
        sum = 0;
        while(!right.empty()) {
            if(right.top() <= T) {
                cout << " " << mp[right.top()];
                right.pop();
            } else {
                left.push(right.top());
                sum += right.top();
                right.pop();
            }
        }
        if(left.empty()) {
            return;
        }
    }
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
