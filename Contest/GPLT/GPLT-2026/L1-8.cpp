#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    while(n--) {
        int op, p, l, r;
        string s1, s2;
        cin >> op;
        if(op == 1) {
            //find;
            cin >> s1;
            if(str.find(s1) == string::npos) {
                cout << "-1" << endl;
            } else {
                int pos = 0;
                bool flag = false;
                int cnt = 0;
                set<int>idx;
                while(str.find(s1, pos) != string::npos) {
                    idx.insert( str.find(s1, pos));
                    pos++;
                }
                for(const auto & x : idx) {
                    cout << (flag ? " " : "") << x;
                    flag = true;
                    cnt++;
                    if(cnt == 3) {
                        break;
                    }
                }
                cout << endl;
            }
        } else if(op == 2) {
            //insert;
            cin >> p >> s2;
            if(p == str.size()) {
                str += s2;
            } else if(p == 0) {
                str = s2 + str;
            } else {
                str.insert(p, s2);
            }
            cout << str << endl;
        } else if(op == 3) {
            //reverse;
            cin >> l >> r;
            string temp;
            for(int i = l; i <= r; i++) {
                temp += str[i];
            }
            reverse(temp.begin(), temp.end());
            str.replace(l, temp.size(), temp);
            cout << str << endl;
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
