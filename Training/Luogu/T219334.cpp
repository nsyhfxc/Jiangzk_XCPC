#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
constexpr int MOD = 1e9 + 7;


int main() {
    string s;
    cin >> s;
    stack<i32> nums;
    stack<char> ops;
    auto priority = [&](char op)-> int {
        if (op == '*') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    };
    auto compute = [&](stack<i32> &numstk, stack<char> &opstk)-> void {
        if (numstk.size() < 2) return;
        i32 b = numstk.top();
        numstk.pop();
        i32 a = numstk.top();
        numstk.pop();
        char op = opstk.top();
        opstk.pop();

        i32 res = 0;
        if (op == '+') res = (a + b) % mod;
        else if (op == '-') res = (a - b + mod) % mod;
        else if (op == '*') res = (a * b) % mod;

        numstk.push(res);
    };
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            i32 val = 0;
            while (i < s.length() && isdigit(s[i])) {
                val = (val * 10 + (s[i] - '0')) % mod;
                i++;
            }
            nums.push(val);
            i--;
        } else if (s[i] == '(') {
            ops.push('(');
        } else if (s[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                compute(nums, ops);
            }
            if (!ops.empty()) ops.pop();
        } else {
            while (!ops.empty() && ops.top() != '(' && priority(ops.top()) >= priority(s[i])) {
                compute(nums, ops);
            }
            ops.push(s[i]);
        }
    }
    while (!ops.empty()) {
        compute(nums, ops);
    }
    cout << nums.top() << endl;

    return 0;
}
