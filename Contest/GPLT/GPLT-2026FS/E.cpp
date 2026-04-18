#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    stack<int> stk1;
    stack<int> stk2;
    bool del = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            stk1.push(x);
            stk2.push(x);
        } else {
            if (x % stk1.top() != 0 && !del) {
                stk1.pop();
                stk1.push(x);
                del = true;
            } else {
                stk1.push(x);
                stk2.push(x);
            }
        }
    }
    vector<int> arr1, arr2;
    while (!stk1.empty()) {
        arr1.push_back(stk1.top());
        stk1.pop();
    }
    while (!stk2.empty()) {
        arr2.push_back(stk2.top());
        stk2.pop();
    }
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());

    auto check = [&](const vector<int> &nums)-> bool {
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] % nums[i - 1] != 0) {
                return false;
            }
        }
        return true;
    };
    if (check(arr1) || check(arr2)) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
